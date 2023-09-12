import java.util.Arrays;

 //for code that runs one time place all code in setup.
 void setup(){
   size(1200,600);

   //String messageToEncode = "The message is encoded using LSBSteganography only when the red/blue values end in 000.";
   String messageToEncode = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+|\':.,?";
   PImage img = loadImage("cat.png");

   //load the image into an array of pixels.
   img.loadPixels();
   //you can use img.pixels[index] to access this array

   //STEP ONE
   //convert the string into an array of ints in the range 0-3
   
   int[]parts = new int[messageToEncode.length() * 4];
   for (int i = 0; i < messageToEncode.length(); i++) {
       int oneChar = parseInt(messageToEncode.charAt(i));
       //println(oneChar);
       parts[(i * 4) + 3] = oneChar & 3;
       oneChar = oneChar >> 2;
       parts[(i * 4) + 2] = oneChar & 3;
       oneChar = oneChar >> 2;
       parts[(i * 4) + 1] = oneChar & 3;
       oneChar = oneChar >> 2;
       parts[(i * 4)] = oneChar & 3;
       oneChar = oneChar >> 2;
   }
   //println(parts);
   
   //add those values to the correct pixels!
   //when the red and blue end in 000, modify the last 2 bits of green.
   //when no more message is left to encode, change the end of the red+blue from 000 to 001.
   int messageCounter = 0;
   for (int i = 0; i < img.pixels.length; i++) {
     int red = (int) red(img.pixels[i]);
     int green = (int) green(img.pixels[i]);
     int blue = (int) blue(img.pixels[i]);
     if ((red & 7) == 0 && (blue & 7) == 0) {
       if (messageCounter < parts.length) {
         //println("True");
         //println("Red:   " + binary(red));
         //println("Green: " + binary(green));
         //println("Blue:  " + binary(blue));
         //println("Parts: " + binary(parts[messageCounter], 2));
         green = green & (255 - 3) | parts[messageCounter];
         //println("NewGreen: " + binary(green));
         img.pixels[i] = color(red, green, blue);
         messageCounter++;
       }
       else if (messageCounter >= parts.length) {
         //println("False");
         //println("Red:   " + binary(red));
         //println("Green: " + binary(green));
         //println("Blue:  " + binary(blue));
         red |= 1;
         blue |= 1;
         //println("NewRed: " + binary(red));
         //println("NewBlue: " + binary(blue));
         img.pixels[i] = color(red, green, blue);
       }
     }
   }

   //write the pixel array to the image.
   img.updatePixels();
   //save the image to disk.
   img.save("modifiedCat.png");
   exit();
 }
