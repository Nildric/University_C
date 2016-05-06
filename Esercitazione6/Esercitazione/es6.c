/*
 * 857179	Federico Longhin
 */

#include <stdio.h>
#include <math.h>

int main() {
    int menuEntry = 1;

    double x1, y1, x2, y2, x3, y3;
    double numerator, denominator;
    double m, q, distance;
    double length1, length2, length3;
    double perimeter, area;

    do {
        printf("Choose the part to execute:\n\t1 \t: Part 1 (Line between two points)\n\t2 \t: Part 2 (Line-point distance)\n\t3 \t: Part 3 (Triangle area)\n\tother \t: Exit\n\n");
        scanf("%i", &menuEntry);

        if (menuEntry == 1) {
            printf("Enter the value of x1:\n");
            scanf("%lf", &x1);
            printf("Enter the value of y1:\n");
            scanf("%lf", &y1);
            printf("Enter the value of x2:\n");
            scanf("%lf", &x2);
            printf("Enter the value of y2:\n");
            scanf("%lf", &y2);

            if (x1 == x2 && y1 == y2) {
                printf("The given points are equals.\n");
            } else if (x1 == x2 && y1 != y2) {
                printf("The line is vertical.\n");
            } else {
                numerator = y2 - y1;
                denominator = x2 - x1;
                m = numerator / denominator;

                numerator = (x2 * y1) - (x1 * y2);
                denominator = x2 - x1;
                q = numerator / denominator;

                if (m == 0 && q != 0) {
                    printf("The equation of the line is constant: y = %.3f\n", q);
                } else if (m != 0 && q == 0) {
                    printf("The equation of the line goes through the origin: y = %.3f * x\n", m);
                } else {
                    printf("The equation of the line is: y = %.3f*x + %.3f\n", m, q);
                }
            }
        }

        if (menuEntry == 2) {
            printf("Enter the coefficient 'm' of the line:\n");
            scanf("%lf", &m);
            printf("Enter the coefficient 'q' of the line:\n");
            scanf("%lf", &q);
            printf("Enter the value of x1:\n");
            scanf("%lf", &x1);
            printf("Enter the value of y1:\n");
            scanf("%lf", &y1);

            numerator = fabs(y1 - ((m * x1) + q));
            denominator = sqrt(1 + (pow(m, 2)));
            distance = numerator / denominator;

            printf("The distance is %.3f\n", distance);
        }

        if (menuEntry == 3) {
            printf("Enter the value of x1:\n");
            scanf("%lf", &x1);
            printf("Enter the value of y1:\n");
            scanf("%lf", &y1);
            printf("Enter the value of x2:\n");
            scanf("%lf", &x2);
            printf("Enter the value of y2:\n");
            scanf("%lf", &y2);
            printf("Enter the value of x3:\n");
            scanf("%lf", &x3);
            printf("Enter the value of y3:\n");
            scanf("%lf", &y3);

            length1 = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
            length2 = sqrt(pow((x3 - x1), 2) + pow((y3 - y1), 2));
            length3 = sqrt(pow((x3 - x2), 2) + pow((y3 - y2), 2));

            if (length1 < (length2 + length3) && length2 < (length1 + length3) && length3 < (length1 + length2)) {
                perimeter = length1 + length2 + length3;

                numerator = (x1 * (y2 - y3)) + (x2 * (y3 - y1)) + (x3 * (y1 - y2));
                denominator = 2;
                area = fabs(numerator / denominator);

                printf("Triangle perimeter is: %.3f\n", perimeter);
                printf("Triangle area is: %.3f\n", area);
            } else {
                printf("The input triangle is not valid.\n");
            }
        }
    } while ((menuEntry == 1 || menuEntry == 2 || menuEntry == 3));

    return 0;
}
