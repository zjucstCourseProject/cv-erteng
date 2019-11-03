import matplotlib.pyplot as plt
import cv2

# params 

IMG_FILE = 'raw.jpg'


img=cv2.imread(IMG_FILE)
cv2.imshow('raw img',img)

# gratlize
gray=cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)

print(img.shape)

# hough circle
circles= cv2.HoughCircles(gray,cv2.HOUGH_GRADIENT,1,100,param1=100,param2=30,minRadius=5,maxRadius=300)

print('circles ans = ',circles)

print('number of circles = ',len(circles[0]))


# circleans
for circle in circles[0]:
    print(circle[2])
    x=int(circle[0])
    y=int(circle[1])
    r=int(circle[2])
    img=cv2.circle(img,(x,y),r,color =(255,255,255),thickness=5)
# circles graph
cv2.imshow('res',img)


cv2.waitKey(0)
cv2.destroyAllWindows()