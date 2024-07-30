import base64
import cv2 as cv
import sys
import numpy as np

print('Script that convert image in b64')
if(len(sys.argv)==1):
    print('Missing parameters')
    print('Usage : \n\tpython3', sys.argv[0], ' image1 ...')
    exit(1)
f = open('image.txt','w')
for image in sys.argv[1:]:
    print(f'Converting {image} ...')
    img = cv.imread(image)
    
    # img.encode('utf-8')
    img_jpg = cv.imencode('.png',img)
    b64 = base64.b64encode(img_jpg[1]).decode('utf-8')
    if f != None:
        f.write(f'<div>\n<img\nsrc="data::image/png;base64,{b64}">\n<\div>\n')
        f.write('\nTHE END\n')
if f != None:
    f.close()