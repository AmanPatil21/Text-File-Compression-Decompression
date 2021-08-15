# Text-File-Compression-Decompression-

- Implemented text file compression using LZW compresion technique.
- This algorithm is typically used in GIF and optionally in PDF and TIFF.
- This algorithm is typically used in Unix’s ‘compress’ command, among other uses.
- It is lossless, meaning no data is lost when compressing. 
- The algorithm is simple to implement and has the potential for very high throughput in hardware implementations. 
- It is the algorithm of the widely used in the GIF image format.

# Features:
- Both compresses and decompresses text files .
- It also handles Folder and compress all the files inside folder  and output new folder with all compresses files .
- It decompress  only those files which are compressed by this project .
- It stores compressed file in binary file format .
# Usage
- Clone the repository on your machine.
- Open Terminal and change directory to the project directory.
- Type command ' make all' which will compile the required files and generate executable file.
- project  [-c] | [-d] [File or Folder Name ] [-o] [Output File/Foleder name ]

# Results :
- Using this project we can compress up 19 kB of file 
- Output :
- Input File Name     :     D:\sycomp\test\1.txt
- Input file size     :     2844    bytes
- Output file size    :     1670    bytes
- Compression Ratio   :     1.70:1
