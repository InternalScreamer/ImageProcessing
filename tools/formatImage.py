
import imageio
import numpy as np
import os

    
class formatImage:
    #todo: Need to add input checking for filepath
    def __init__(self, filepath):
        self.filename = filepath.split('/')[-1]
        raw = imageio.imread(filepath)
        self.payload = None
        self.mode = 0
        self.width = int(raw.shape[0])
        self.height = int(raw.shape[1])
        if len(im.shape) == 2:
            self.payload = raw.ravel()
        else:
            self.mode = im.shape[2] - 2
            r = raw[:,:,0].ravel()
            g = raw[:,:,1].ravel()
            b = raw[:,:,2].ravel()
            self.payload = np.concatenate((r,g,b))
            if self.mode == 2:
                payload = np.concatenate((payload, raw[:,:,3].ravel()))

    def outputToFile(self, loc):
        name = self.filename.split('.')[0]
        fileout = open(loc + name, 'wb')
        header_start = (0x1234).to_bytes(2, byteorder='big')
        mode = (self.mode).to_bytes(1, byteorder='big')
        width = (self.width).to_bytes(4, byteorder='big')
        height = (self.height).to_bytes(4, byteorder='big')
        header_end = (0x5678).to_bytes(2, byteorder='big')
        end_pattern = (0x12345678).to_bytes(4, byteorder='big')
        header = [header_start, mode, width, height, header_end]
        for val in header:
            fileout.write(val)
        fileout.write((self.payload.tobytes()))
        fileout.write(end_pattern)
        fileout.close()
        
#for testing purposes
if __name__ == "__main__":
    im = imageio.imread(file)
    dim = im.shape
    print(dim)
    
    x = formatImage(file)
    x.outputToFile(loc)