#include <iostream>
#include <stdio.h>
using namespace std;

class complex_number 
{
    private:
        double re, img;
    public:
        double get_re(){ return re;};
        double get_img(){ return img;};
        void set_re(double x){ re=x; };
        void set_img(double y) { img = y; };
        static void swap_cn(complex_number *cn_a, complex_number *cn_b)
        {
            double temp_re = cn_a->get_re();
            double temp_img =  cn_a->get_img();
            cn_a->set_re(cn_b->get_re());
            cn_a->set_img(cn_b->get_img());
            cn_b->set_re(temp_re);
            cn_b->set_img(temp_img);
        }
        static bool is_smaller(complex_number cn_a, complex_number cn_b)
        {
            return (cn_a.get_re() < cn_b.get_re()) || ((cn_a.get_re() == cn_b.get_re()) && (cn_a.get_img() < cn_b.get_img()));
        }
        // A function to implement bubble sort
        static void bubbleSort(complex_number *arr, int ROW, int COL)
        {
            int n = ROW * COL;
            for (int i=0; i<n-1; i++)
            {
                for (int j=0; j<n-i-1; j++)
                {
                    complex_number *cn_a = arr+j;
                    complex_number *cn_b = arr+j+1;

                    if (complex_number::is_smaller(*cn_b, *cn_a)) // cn_a > cn_b
                    {
                        complex_number::swap_cn(cn_a, cn_b);
                    }
                }
            }
        }
};

int main()
{
    /*------ setting a matrix -----*/
    int ROW_SIZE = 4;
    int COL_SIZE = 4;
    complex_number cn_array[ROW_SIZE][COL_SIZE];

    cout << "Original Matrix of Complex Numbers " << endl;
    for(int row=0; row<ROW_SIZE; row++)
    {
        for(int col=0; col<COL_SIZE; col++)
        {
            double x = (double) (rand()%10);
            double y = (double) (rand()%10);
            cn_array[row][col].set_re(x);
            cn_array[row][col].set_img(y);
            cout << cn_array[row][col].get_re()  << "+j" << cn_array[row][col].get_img() << " ";
        }
        printf("\n");
    }
    printf("\n");
    cout << "Sorted Matrix of Complex Numbers " << endl;
    
    complex_number::bubbleSort((complex_number *)cn_array, ROW_SIZE, COL_SIZE);

    for(int row=0; row<ROW_SIZE; row++)
    {
        for(int col=0; col<COL_SIZE; col++)
        {
            cout << cn_array[row][col].get_re()  << "+j" << cn_array[row][col].get_img() << " ";
        }
            printf("\n");
    }

    return 0;
}
