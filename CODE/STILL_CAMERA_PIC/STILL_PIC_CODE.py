import urllib.request
import cv2
import numpy as np
import time

# IP address of the ESP32-CAM module
# Use the IP address which is given by Serial Monitor of Arduino IDE
ip_address = '192.168.1.58'

# Capture URL
capture_url = f'http://{ip_address}/capture'


# Function to capture and save an image
def capture_and_save_image(image_counter):
    try:
        # Send a request to capture an image
        response = urllib.request.urlopen(capture_url)

        # Read the image data
        image_data = response.read()

        # Convert the image data to a NumPy array
        image_array = np.frombuffer(image_data, dtype=np.uint8)

        # Decode the image array using OpenCV
        image = cv2.imdecode(image_array, cv2.IMREAD_COLOR)

        # Save the image to a file
        image_filename = f'captured_image_{image_counter}.jpg'
        cv2.imwrite(image_filename, image)

        print(f'Image {image_counter} captured and saved as {image_filename}.')
    except Exception as e:
        print(f'Error capturing or saving image: {e}')


# Number of images to capture
num_images_to_capture = 10

# Time interval between captures (in seconds)
capture_interval = 5

# Capture and save images at regular intervals
for i in range(num_images_to_capture):
    capture_and_save_image(i + 1)
    time.sleep(capture_interval)

print('All images captured and saved.')