# ACL (AtCoder Library)

https://github.com/atcoder/ac-library?tab=readme-ov-file

## Install

```sh
curl -OL https://github.com/atcoder/ac-library/releases/download/v1.5.1/ac-library.zip
unzip -j ac-library.zip "atcoder/*" -d ./atcoder
rm ac-library.zip
```

## Compile and run

```sh
make t=practice_1.cpp
./a.out
make clean
```

## Resize images

```sh
magick assets/in.jpg  -strip -sampling-factor 4:2:0 -adaptive-resize 50% -quality 50 -gaussian-blur 0.05 -interlace JPEG -colorspace RGB assets/out.jpg
```
