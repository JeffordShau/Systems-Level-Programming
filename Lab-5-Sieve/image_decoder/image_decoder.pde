import java.util.Arrays;

 //for code that runs one time place all code in setup.
 void setup(){
   size(1200,600);
   //println(unbinary("01010001"));
   PImage img = loadImage("modifiedCat.png");
   img.loadPixels();
   int[]parts = new int[img.width * img.height];
      
   int messageCounter = 0;
   for (int i = 0; i < img.pixels.length; i++) {
     int red = (int) red(img.pixels[i]);
     int green = (int) green(img.pixels[i]);
     int blue = (int) blue(img.pixels[i]);
     if ((red & 7) == 0 && (blue & 7) == 0) {
       //println("True");
       //println(binary(red));
       //println(binary(green));
       //println(binary(blue));
       parts[messageCounter] = (green & 3);
       messageCounter += 1;
       //println(i + ": " + binary(green & 3, 2));
     }
   }
   //println(parts);
   
   String decryptedMessage = "";
   int sum = 0;
   for (int i = 0; i < messageCounter / 4; i++) {
     for (int j = 0; j < 4; j++) {
       //println(parts[(i * 4) + (3 - j)]);
       sum += (parts[(i * 4) + (3 - j)] & 1) * (int) Math.pow(2, 2 * j);
       sum += (parts[(i * 4) + (3 - j)] & 2) / 2 * (int) Math.pow(2, 2 * j + 1);
       //println("Sum: " + sum);
     }
     char oneChar = (char) (sum);
     //println(oneChar);
     decryptedMessage = decryptedMessage.concat(String.valueOf(oneChar));
     sum = 0;
     //break;
   }
   //println("result");
   println(decryptedMessage);
    //println(unbinary("01010100"));
   // 01101000
   // 01100101

   //write the pixel array to the image.
   //img.updatePixels();
   //save the image to disk.
   //img.save("modifiedCat.png");
   exit();
 }
