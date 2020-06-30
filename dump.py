import cv2 # computer vision library
import helpers

import numpy as np
import matplotlib.pyplot as plt
import matplotlib.image as mpimg

%matplotlib inline

## TODO: Resize image so that all "standard" images are the same size 600x1100 (hxw)
# Compute biggest scale ratio
img_x, img_y, img_z = image.shape
scale_x = img_x / 600.0
scale_y = img_y / 1100.0
if scale_x < scale_y:
    scale = scale_x
else:
    scale = scale_y

# Scale image
img_x_scaled = int(image.shape[0] / scale)
img_y_scaled = int(image.shape[1] / scale)
img_resized = cv2.resize(image, (img_y_scaled, img_x_scaled))

# Crop image
return img_resized[:600, :1100]