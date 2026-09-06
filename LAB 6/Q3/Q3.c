#include <stdio.h>
#include <math.h>

#define PI 3.141592653589793

typedef struct {
    double real, imag;
} Complex;

// Complex addition
Complex add(Complex a, Complex b) {
    Complex c = {a.real + b.real, a.imag + b.imag};
    return c;
}

// Complex subtraction
Complex sub(Complex a, Complex b) {
    Complex c = {a.real - b.real, a.imag - b.imag};
    return c;
}

// Complex multiplication
Complex mul(Complex a, Complex b) {
    Complex c = {
        a.real * b.real - a.imag * b.imag,
        a.real * b.imag + a.imag * b.real
    };
    return c;
}

// FFT
void fft(Complex *a, int n, int invert) {
    if (n == 1) return;

    Complex even[n/2], odd[n/2];
    for (int i = 0; i < n/2; i++) {
        even[i] = a[2*i];
        odd[i] = a[2*i+1];
    }

    fft(even, n/2, invert);
    fft(odd, n/2, invert);

    double ang = 2 * PI / n * (invert ? -1 : 1);
    Complex w = {1, 0};
    Complex wn = {cos(ang), sin(ang)};

    for (int i = 0; i < n/2; i++) {
        Complex t = mul(w, odd[i]);
        a[i] = add(even[i], t);
        a[i + n/2] = sub(even[i], t);

        w = mul(w, wn);
    }

    if (invert) {
        for (int i = 0; i < n; i++) {
            a[i].real /= 2;
            a[i].imag /= 2;
        }
    }
}

// Convolution
void convolution(double *A, int m, double *B, int n) {
    int size = 1;
    while (size < m + n) size <<= 1;

    Complex fa[size];
    for (int i = 0; i < size; i++) {
        fa[i].real = (i < m) ? A[i] : 0;
        fa[i].imag = 0;
    }

    Complex fb[size];
    for (int i = 0; i < size; i++) {
        fb[i].real = (i < n) ? B[i] : 0;
        fb[i].imag = 0;
    }

    fft(fa, size, 0);
    fft(fb, size, 0);

    for (int i = 0; i < size; i++)
        fa[i] = mul(fa[i], fb[i]);

    fft(fa, size, 1);

    printf("Convolution result:\n");
    for (int i = 0; i < m + n - 1; i++)
        printf("%.0f ", fa[i].real);
}

int main() {
    int m, n;
    printf("Enter size of A: ");
    scanf("%d", &m);

    double A[m];
    printf("Enter A:\n");
    for (int i = 0; i < m; i++)
        scanf("%lf", &A[i]);

    printf("Enter size of B: ");
    scanf("%d", &n);

    double B[n];
    printf("Enter B:\n");
    for (int i = 0; i < n; i++)
        scanf("%lf", &B[i]);

    convolution(A, m, B, n);
    return 0;
}
