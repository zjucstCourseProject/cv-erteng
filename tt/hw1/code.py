"""
course work for cv
put text on pic

@author : Zhitao Zou
"""

import PIL
from PIL import ImageFont
from PIL import Image
from PIL import ImageDraw

# parameter

text = r'邹智滔21951114' # 学号+ 姓名
font_size = 150
imageFile = "fbcity.jpg"
TARGET_FILE_NAME = 'answer.jpg'
im1=Image.open(imageFile)
position = (0, im1.size[1]-font_size - font_size//2)
RGB_COLOR = "#ff0000"
fnt=ImageFont.truetype("c:/Windows/Fonts/msyh.ttc", font_size)

draw = ImageDraw.Draw(im1)
draw.text(position,text,fill=RGB_COLOR,font=fnt)
draw = ImageDraw.Draw(im1)

im1.save(TARGET_FILE_NAME)