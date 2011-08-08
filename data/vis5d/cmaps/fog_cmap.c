


#include <stdio.h>



main (int argc, char *argv[])
{

    int		i;
    float	alpha, alpha_max, alpha_min, alpha_d;



    alpha_max = 255;
    if (argc > 1) alpha_max = atof (argv[1]);
    if (argc > 2)
    {
        alpha_min = alpha_max;
        alpha_max = atof (argv[1]);
    }
    alpha_d = (alpha_max - alpha_min) / 254.0;


    printf ("0.0, 1.0, 1.4, 1.0\n");

    alpha = alpha_min;
    for (i = 0; i < 255; i++)
    {
        printf ("255 255 255 %.0f\n", alpha);
        alpha += alpha_d;
    }


    return 1;
}
