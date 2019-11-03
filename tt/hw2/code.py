import numpy as np
import cv2
import matplotlib.pyplot as plt
from noise import gauss_noise,sp_noise


test = lambda img: [
cv2.blur(img, (5,5)),
cv2.GaussianBlur(img,(5,5),0),
cv2.medianBlur(img, 5)
]


IMG_FILE = r'lena.jpg'



img = cv2.imread(IMG_FILE)




salt = sp_noise(img)

gauss = gauss_noise(img)

salt_test = test(salt)
gauss_test = test(gauss)

r,c = 2,4

pic = [[salt] + salt_test,[gauss] + gauss_test]
for pic_idx in range(r*c):
    plt.subplot(r,c,pic_idx+1)
    plt.imshow(pic[pic_idx // 4][pic_idx%4])

plt.show()