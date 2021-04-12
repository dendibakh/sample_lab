import sys
import subprocess
import os
import shutil
import argparse
import json

parser = argparse.ArgumentParser(description='test results')
parser.add_argument("-threshold", type=float, help="required ratio (in percents) between the submission and the baseline", default=10.0)
parser.add_argument("-jsonfile", type=str, help="path to the JSON file with result", default="")

args = parser.parse_args()

threshold = args.threshold

f = open(args.jsonfile,)

data = json.load(f)

old = data[0]['measurements'][0]['real_time']
new = data[0]['measurements'][0]['real_time_other']

f.close()

diff = new - old

if diff > 0:
  print ("New version is slower. Submissions failed.")
  sys.exit(1)

speedup = (abs(diff) / old ) * 100

if (speedup < threshold):
  print ("New version is not fast enough. Submissions failed.")
  print ("Measured speedup:", "{:.2f}".format(speedup), "%")
  print ("Pass threshold:", "{:.2f}".format(threshold), "%")
  sys.exit(1)

print ("Measured speedup:", "{:.2f}".format(speedup), "%")
print ("Submissions succeded")
sys.exit(0)
