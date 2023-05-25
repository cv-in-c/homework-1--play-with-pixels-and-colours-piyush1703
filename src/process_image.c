#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#include "image.h"

float get_pixel(image im, int x, int y, int c)
{
    // TODO Fill this in
    return im->data[x*255*255+y*255+z];
    return 0;
}

void set_pixel(image im, int x, int y, int c, float v)
{
    // TODO Fill this in
    if(v>=0 && v<256){
        im->data[x*255*255+y*255+z]=v;
    }
}

image copy_image(image im)
{
    image copy = make_image(im.w, im.h, im.c);
    memcpy(copy,im,sizeof(im));
    // TODO Fill this in
    return copy;
}

image rgb_to_grayscale(image im)
{
    assert(im.c == 3);
    image gray = make_image(im.w, im.h, 1);
    for(int i=0;i<256;i++){
        for(int j=0;j<256;j++){
            float r=get_pixel(im,i,j,0);
             float g=get_pixel(im,i,j,1);
             float b=get_pixel(im,i,j,2);
            float y=0.299*r + 0.587*g + .114*b;
            set_pixel(gray,i,j,0,y);
        }
    }
    // TODO Fill this in
    return gray;
}

void shift_image(image im, int c, float v)
{
    // TODO Fill this in
    for(int i=0;i<256;i++){
        for(int j=0;j<256;j++){
           for(int z=0;z<c;z++){
            set_pixel(im,i,j,z,get_pixel(im,i,j,z)+v);
           }
        }
    }
    
}

void clamp_image(image im)
{
    // TODO Fill this in
    for(int i=0;i<256;i++){
        for(int j=0;j<256;j++){
           for(int z=0;z<c;z++){
            set_pixel(im,i,j,z,get_pixel(im,i,j,z)/255);
           }
        }
    }
}


// These might be handy
float three_way_max(float a, float b, float c)
{
    return (a > b) ? ( (a > c) ? a : c) : ( (b > c) ? b : c) ;
}

float three_way_min(float a, float b, float c)
{
    return (a < b) ? ( (a < c) ? a : c) : ( (b < c) ? b : c) ;
}

void rgb_to_hsv(image im)
{
    // TODO Fill this in
    for(int i=0;i<256;i++){
        for(int j=0;j<256;j++){
            float r=get_pixel(im,i,j,0);
             float g=get_pixel(im,i,j,1);
             float b=get_pixel(im,i,j,2);
            float v=three_way_max(r,g,b);
            float m=three_way_min(r,g,b);
            float c=v-m;
            float s=c/v;
            float h;
            if(c==0) h=0;
            else h=c/360;
            set_pixel(gray,i,j,0,h);
            set_pixel(gray,i,j,1,s);
            set_pixel(gray,i,j,2,v);
        }
    }
}

void hsv_to_rgb(image im)
{
    // TODO Fill this in
    for(int i=0;i<256;i++){
        for(int j=0;j<256;j++){
            float h=get_pixel(im,i,j,0);
             float s=get_pixel(im,i,j,1);
             float v=get_pixel(im,i,j,2);
            float c;
            if(h==0) c=0;
            else c=h*360;
            float m=v-c;
            float b=m;
            float g=c/v;
            float r=v;
            set_pixel(gray,i,j,0,r);
            set_pixel(gray,i,j,1,g);
            set_pixel(gray,i,j,2,b);
        }
    }
    
}
