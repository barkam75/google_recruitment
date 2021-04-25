//Rainwater excercise
#include <cstddef>
#include <iostream>

using namespace std;
enum states_d
{
    stopped,
    counting,
    flush
};
int trapped_rainwater_brute(int numbers[], int length)
{
    int area_tot = 0;
    int n = 0;
    int m;
    while (n < length)
    {
        int left = 0;
        for (m = n; m >= 0; m--)
            if (numbers[m] > left)
                left = numbers[m];
        int right = 0;
        for (m = n; m < length; m++)
            if (numbers[m] > right)
                right = numbers[m];
        int cmp = min(left, right) - numbers[n];
        if (cmp > 0)
            area_tot += cmp;
        n++;
    }
    return area_tot;
}

int trapped_rainwater(int numbers[], int length)
{
    int area_tot = 0; //Total area
    if ((numbers != NULL) && (length >= 3))
    {
        int area_tmp = 0; //Temporary area

        int df = 0;        //Level difference
        int level_prv = 0; //Previous level
        int level_ref = 0; //Refernce level

        int counter = 0;

        int n = 0;
        states_d state = stopped;
        while (n < length)
        {
            df = level_prv - numbers[n];
            switch (state)
            {
            case stopped:
                if (df < 0) //Falling edge detected
                {
                    break;
                }
                else
                {
                    state = counting;
                    level_ref = level_prv; // Set reference level
                }
            case counting:
                counter++;
                if (df < 0)
                {
                    //Rising edge detected
                    if (level_ref <= numbers[n])
                    { //If current number is higher or equal to reference level
                        //Flush all of the integrated area
                        area_tot += area_tmp;
                        area_tmp = 0;
                        counter = 0;
                        level_ref = numbers[n];
                        state = stopped;
                    }
                    else
                    {
                        //If current number is smaller than the reference level make correction (flush only water up to the current number)
                        area_tmp += level_ref - numbers[n];
                        int area_cor = counter * level_ref - numbers[n];
                        area_tot += area_tmp - area_cor;
                        area_tmp = area_cor;
                    }
                }
                else
                {
                    area_tmp += level_ref - numbers[n];
                }
            }
            level_prv = numbers[n];
            n++;
        }
    }
    return area_tot;
}
