//    int color;
//             if (i == max_iter)
//                 color = 0x000000;  // Black for points in the set
//             else
//             {
//                 // Create smooth color transitions based on iteration count
//                 int r = (i * 255 / max_iter);
//                 int g = (i * 127 / max_iter);
//                 int b = (i * 255 / max_iter);
//                 color = (r << 16) | (g << 8) | b;
//             }


// int color = (i * 0x00FF00FF / max_iter);

          // int color;
            // if (i == max_iter)
            //     color = 0x000000;  // Black for the set
            // else if (i > max_iter/1.2)
            //     color = 0x0000FF;  // Bright blue
            // else if (i > max_iter/1.5)
            //     color = 0x0077FF;  // Light blue
            // else if (i > max_iter/2)
            //     color = 0x00AAFF;  // Lighter blue
            // else
            //     color = 0x00FFFF;  // Cyan/white blue




             // int color = (i * 0x00FF00FF / max_iter);
            // int color;
            // if (i == max_iter)
            //     color = 0x00000000;
            // else    
            //     color = 0x000000FF;
            //  int color = (i == max_iter) ? 0x000000 : create_color(i, max_iter);
            //  int color;
            // if (i == max_iter)
            //     color = 0x000000;  // Black for points in the set
            // else
            // {
            //     // Create smooth color transitions based on iteration count
            //     int r = (i * 255 / max_iter);
            //     int g = (i * 127 / max_iter);
            //     int b = (i * 255 / max_iter);
            //     color = (r << 16) | (g << 8) | b;
            // }
            // int color;
            // if (i == max_iter)
            //     color = 0x000000;  // Black for the set
            // else if (i > max_iter/1.2)
            //     color = 0x0000FF;  // Bright blue
            // else if (i > max_iter/1.5)
            //     color = 0x0077FF;  // Light blue
            // else if (i > max_iter/2)
            //     color = 0x00AAFF;  // Lighter blue
            // else
            //     color = 0x00FFFF;  // Cyan/white blue
            // int color;
            // if (i == max_iter)
            //     color = 0x000000;  // Black for the set
            // else
            // {
            //     // Create a smooth blue gradient
            //     int brightness = (i * 255) / max_iter;
            //     int blue = brightness;
            //     int green = (brightness * 50) / 100;  // Subtle green tint
            //     color = (green << 8) | blue;  // Combine into RGB
            // }






                // int color;
        //     if (i == max_iter)
        //         color = 0x000000;      // Black
        //     else
        //         color = 0xFF0000; 
            


            // int color_finder(int i, int max_iter)
// {
//     if (i == max_iter)
//         return 0x000000;
//     return i * 0x000508; // Creates purple-blue gradient
// }
// int color_finder(int i, int max_iter)
// {
//     int colors[] = {
//         0x000000,    // Black
//         0x1E0033,    // Very dark purple
//         0x3B0066,    // Dark purple
//         0x580099,    // Purple
//         0x7500CC,    // Medium purple
//         0x9200FF,    // Bright purple
//         0x7500CC,    // Medium purple
//         0x580099,    // Purple
//         0x3B0066,    // Dark purple
//         0x1E0033     // Very dark purple
//     };
    
//     if (i == max_iter)
//         return 0x000000;
        
//     return colors[i % 10];
// }

// int color_finder(int i, int max_iter)
// {
//     static const int shade = 0x0F0F0F;
    
//     if (i == max_iter)
//         return 0x000000;
    
//     i = i % 16;  // Keep values between 0-15 for smooth repeating
//     return shade * i;  // This creates a nice gradient effect
// }

// int color_finder(int i, int max_iter)
// {
//     if (i == max_iter)
//         return 0x000000;
        
//     i = i * 5;  // Multiply to get more color spread
    
//     if (i > 255)
//         i = 255;
        
//     return i * 0x010101;  // This creates a nice silver/grey gradient
// }

// int color_finder(int i, int max_iter)
// {
//     if (i == max_iter)
//         return 0x000000;
        
//     i = i * 10;  // Multiply for broader color range
    
//     if (i > 255)
//         i = 255;
        
//     return i * 0x000101;  // Creates purple-blue gradient
// }

// int color_finder(int i, int max_iter)
// {
//     if (i == max_iter)
//         return 0x000000;
//     i = i * 10; // Multiply for broader color range
//     if (i > 255)
//         i = 255;
//     return i * 0x000101; // Creates purple-blue gradient
// }