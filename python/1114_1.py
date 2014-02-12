#! /usr/share/python -tt
#! -*- coding utf-8 -*-

import sys
import commands

def list(dir):
    cmd = 'ls -l' + dir
    print 'about to do this:', cmd
    return
    (status, output) = commands.tetstatusoutput(cmd)
    if status:
        sys.stderr.write('there was an error:' + output)
        sys.exit(1)
    print output
