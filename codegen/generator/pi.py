## pi.py
## Copyright 2016 Mac Radigan
## All Rights Reserved

import time
import datetime

ts = datetime.datetime.fromtimestamp(time.time()).strftime('%Y-%m-%d %H:%M:%S')
notice = "NOTICE:  This source file was automatically generated on %s by dox." % ts

ms = [
  ('z',   'complex', '16',  'Complex_Double_t'), 
  ('d',   'real',     '8',  'double'), 
  ('c',   'complex',  '8',  'Complex_Single_t'), 
  ('s',   'real',     '4',  'float'), 
  ('u16', 'integer',  '2',  'uint16_t'), 
  ('u8',  'integer',  '1',  'uint8_t') 
]
for (prefix, fclass, fkind, ctype) in ms:
  ftype = '%s*%s' % (fclass, fkind)
  apply_templates()

## *EOF*
