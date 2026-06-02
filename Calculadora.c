#include <stdio.h>

float sum(float a, float b)
{
    float res = a + b;
    printf("Result: %.2f\n", res);
    return res;
}

float sub(float a, float b)
{
    float res = a - b;
    printf("Result: %.2f\n", res);
    return res;
}

float mult(float a, float b)
{
    float res = a * b;
    printf("Result: %.2f\n", res);
    return res;
}

float div(float a, float b)
{
    if(b == 0)
    {
        printf("Error, isn't possible division of 0\n");
        return a;
    }else
    {
        float res = a / b;
        printf("Result: %.2f\n", res);
        return res;
    }
}

void menu(int history, float accumulator)
{
    printf("/////////////////\n");
    printf("    Calculator    \n");
    printf("/////////////////\n");
    if(history)
    {
        printf("[ Memory: %.2f ] \n", accumulator);
        printf("----------------\n");
    }
    printf("1 - Sum\n");
    printf("2 - Subtraction\n");
    printf("3 - Multiplication\n");
    printf("4 - Division\n");
    printf("5 - History\n");
    printf("0 - Exit\n");
    printf("Choose an option: ");
}

void clear() 
{
    printf("\e[1H\e[2J");
}

void wait()
{
    printf("\nPress Enter to continue...");
    getchar();
    getchar();
}

int main()
{
    int opt;
    float a, b;

    float accumulator = 0;
    int history = 0;
    int optHistory = 0;

    float hist_a[10];
    float hist_b[10];
    float hist_res[10];
    char hist_op[10];   
    int accounts = 0;

    while(1)
    {
        clear();
        menu(history, accumulator);
        scanf("%d", &opt);

        if(opt == 0)
        {
            printf("Exiting...\n");
            return 0;
        }

        if(opt == 5)
        {
            clear();
            printf("//////////////////////\n");
            printf("  Operation History\n");
            printf("//////////////////////\n");
            if(accounts == 0)
            {
                printf("No operations recorded yet.\n");
            }else
            {
                for(int i = 0; i < accounts; i++)
                {
                    if (hist_op[i] == 'E') {                   
                        printf("%d) %.2f / %.2f -> Error: Division by Zero!\n", i + 1, hist_a[i], hist_b[i]);
                    } else {
                        printf("%d) %.2f %c %.2f = %.2f\n", i + 1, hist_a[i], hist_op[i], hist_b[i], hist_res[i]);
                    }
                }
            }
            wait();
            continue;
        }

        if(opt >= 1 && opt <= 4)
        {
            char signal;
            optHistory = 0;

            if(history == 1)
            {
                printf("\nContinue account?\n");
                printf("1 - Yes\n");
                printf("2 - No\n");
                printf("Choose: ");
                scanf("%d", &optHistory);
            }

            if(optHistory == 1)
            {
                a = accumulator;
            }else
            {
                history = 0;
            }
        
            if(history == 0)
            {
                printf("Write number one: ");
                scanf("%f", &a);
            }

            printf("Write number two: ");
            scanf("%f", &b);

            switch(opt)
            {
                case 1:
                    accumulator = sum(a, b);
                    signal = '+';
                    break;
                case 2:
                    accumulator = sub(a, b);
                    signal = '-';
                    break;
                case 3:
                    accumulator = mult(a, b);
                    signal = '*';
                    break;
                case 4:
                    if (b == 0) {
                        signal = 'E';
                    } else {
                        signal = '/';
                    }
                    accumulator = div(a, b);
                    break;
            }
        
            if(accounts < 10)
            {
                hist_a[accounts] = a;
                hist_b[accounts] = b;
                hist_res[accounts] = accumulator; 
                hist_op[accounts] = signal;
                accounts++;
            }else
            {
                for(int i = 1; i < 10; i++)
                {
                    hist_a[i - 1] = hist_a[i];
                    hist_b[i - 1] = hist_b[i];
                    hist_res[i - 1] = hist_res[i];
                    hist_op[i - 1] = hist_op[i];
                }

                hist_a[9] = a;
                hist_b[9] = b;
                hist_res[9] = accumulator; 
                hist_op[9] = signal;
            }
            
            history = 1; 
            wait();
        }
        else
        {
            printf("The choice isn't possible! Choose another.\n");
            wait();
        }
    }
}