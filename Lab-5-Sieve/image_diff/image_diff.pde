import java.util.Arrays;
//import java.awt.Color;

PImage img;
PImage img2;

 //for code that runs one time place all code in setup.
 void setup(){
   size(1200,600);

   img = loadImage("cat.png");
   img2 = loadImage("modifiedCat.png");

   //load the image into an array of pixels.
   img.loadPixels();
   img2.loadPixels();
   //you can use img.pixels[index] to access this array

   for (int i = 0; i < img.pixels.length; i++) {
     int Ored = (int) red(img.pixels[i]);
     int Ogreen = (int) green(img.pixels[i]);
     int Oblue = (int) blue(img.pixels[i]);
     int Nred = (int) red(img2.pixels[i]);
     int Ngreen = (int) green(img2.pixels[i]);
     int Nblue = (int) blue(img2.pixels[i]);
     if ((Ored & 7) == (Nred & 7) && (Oblue & 7) == (Nblue & 7) && (Ored & 7) == 0 && (Oblue & 7) == 0) {
       //println(i);
       img2.pixels[i] = color(0, 255, 0); // green
     }
     else if ((Ogreen & 7) == (Ngreen & 7) && ((Ored & 7) != (Nred & 7) | (Oblue & 7) != (Nblue & 7))) {
       //println(i);
       img2.pixels[i] = color(255, 0, 255);  // purple
     }
   }

   //write the pixel array to the image.
   img2.updatePixels();
   //img2.save("newmodifiedCat.png");
   //save the image to disk.
   //img.save("modifiedCat.png");
   //println(img.width, img.height);
 }
 
 void draw() {
  //PImage img3 = loadImage("newmodifiedCat.png");
  image(img2, 0, 0);
}
