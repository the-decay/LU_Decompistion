#include<stdio.h>

int num1, den1, num2 , den2 , den3, num3;
int u11n, u12n, u13n, u21n=0, u22n, u23n, u31n=0, u32n=0, u33n;
int l11n=1, l12n=0, l13n=0, l21n, l22n=1, l23n=0, l31n, l32n, l33n=1;

int u11d=1, u12d=1, u13d=1, u21d=1, u22d=1, u23d=1, u31d=1, u32d=1, u33d=1;
int l11d=1, l12d=1, l13d=1, l21d=1, l22d=1, l23d=1, l31d=1, l32d=1, l33d=1;

int x1, y1, z1, x2, y2, z2, x3, y3, z3, d1, d2, d3;

int V1, V2n, V2d, V3n, V3d;

int gcd(int a, int b) {
    if (a == 0) 
        return b; 
    return gcd(b % a, a); 
} 

void l_form (int& den3, int& num3) {
    int common_factor = gcd(num3, den3); 

    den3 = den3 / common_factor; 
    num3 = num3 / common_factor; 
} 

void a_Frack(int num1, int den1, int num2, int den2, int& num3, int& den3) { 
    den3 = gcd(den1, den2); 
    den3 = (den1 * den2) / den3; 
	num3 = (num1) * (den3 / den1) + (num2) * (den3 / den2);
    l_form(den3, num3); 
}

void s_Frack(int num1, int den1, int num2, int den2, int& num3, int& den3) { 
    den3 = gcd(den1, den2); 
    den3 = (den1 * den2) / den3; 
	num3 = (num1) * (den3 / den1) - (num2) * (den3 / den2);
    l_form(den3, num3); 
}

void m_Frack(int num1, int den1, int num2, int den2, int& num3, int& den3) { 
    num3 = num1*num2;
	den3 = den1*den2;
    l_form(den3, num3); 
}

void d_Frack(int num1, int den1, int num2, int den2, int& num3, int& den3) { 
    num3 = num1*den2;
	den3 = den1*num2;
    l_form(den3, num3); 
}

void f_cal(int a, int b, char x, int c, int d) {
	switch (x)
	{
		case '+':
			a_Frack(a, b, c, d, num3, den3);
			break;
		
		case '-':
			s_Frack(a, b, c, d, num3, den3);
			break;
			
		case '*':
			m_Frack(a, b, c, d, num3, den3);
			break;
			
		case '/':
			d_Frack(a, b, c, d, num3, den3);
			break;		
	}
		
}

void scan() {
	
	printf("Enter the Matrix below in this format:\n\n");
	printf("First, |a11 a12 a13|\n");
	printf("       |a21 a22 a23|\n");
	printf("       |a31 a32 a33|\n\n");
	printf("Next, |x|\n");
	printf("      |y|\n");
	printf("      |z|\n\n");
	printf("P.S. - No Need for '|'\n\n");
	scanf("%d",&x1);	scanf("%d",&y1);	scanf("%d",&z1);
	scanf("%d",&x2);	scanf("%d",&y2);	scanf("%d",&z2);
	scanf("%d",&x3);	scanf("%d",&y3);	scanf("%d",&z3);
	scanf("%d",&d1);	scanf("%d",&d2);	scanf("%d",&d3);
}

void set1() {
	x1=1;
	y1=2;
	z1=3;
	x2=2;
	y2=3;
	z2=4;
	x3=3;
	y3=4;
	z3=1;
	d1=14;
	d2=20;
	d3=14;
}

void set2() {
	x1=3;
	y1=2;
	z1=7;
	x2=2;
	y2=3;
	z2=1;
	x3=3;
	y3=4;
	z3=1;
	d1=4;
	d2=5;
	d3=7;
}

void fPrint() {
	 printf("    |%d  %d  %d| |x| = |%d|\n",x1, y1, z1, d1);
	 printf("    |%d  %d  %d| |y| = |%d|\n",x2, y2, z2, d2);
	 printf("    |%d  %d  %d| |z| = |%d|\n\n",x3, y3, z3, d3);
}

void sPrint() {
	 printf("|%d  %d  %d|     | 1    0   0|  |u11  u12  u13|\n", x1, y1, z1);
	 printf("|%d  %d  %d|  =  |l21   1   0|  | 0   u22  u23|\n", x2, y2, z2);
	 printf("|%d  %d  %d|     |l31  l32  1|  | 0    0   u33|\n\n", x3, y3, z3);
}

void tPrint() {
	 printf("|%d  %d  %d|     |u11      u12                u13                    |\n", x1, y1, z1);
	 printf("|%d  %d  %d|  =  |l21      l21 u12 + u22      l21 u13 + u23          |\n", x2, y2, z2);
	 printf("|%d  %d  %d|     |l31 u11  l31 u12 + l32 u22  l31 u12 + l32 u23 + u33|\n\n", x3, y3, z3);
}

void foPrint() {

	printf("   A = | 1    0    0 |  |%d/%d  %d/%d  %d/%d|\n", u11n, u11d, u12n, u12d, u13n, u13d);
	printf("       |%d/%d   1    0 |  | 0   %d/%d  %d/%d|\n",   l21n, l21d, u22n, u22d, u23n, u23d);
	printf("       |%d/%d  %d/%d   1 |  | 0    0   %d/%d|\n\n", l31n, l31d, l32n, l32d, u33n, u33d);
}

void fiPrint() {
	 printf(" => | 1    0    0 | |V1|   |%d|\n", d1);
	 printf("    |%d/%d   1    0 | |V2| = |%d|\n",  l21n, l21d, d2);
	 printf("    |%d/%d  %d/%d   1 | |V3|   |%d|\n\n",l31n, l31d, l32n, l32d, d3);
}

void siPrint() {
	
	printf("    |V1| = |%d|\n",d1);
	printf("    |%dV1/%d + V2| = |%d|\n",l21n, l21d, d2);
	printf("    |%dV1/%d + %dV2/%d + V3| = |%d|\n\n",l31n, l31d, l32n, l32d, d3);
}

void sePrint() {
	printf("->  V =|V1| = |%d|\n",V1);
	printf("       |V2| = |%d/%d|\n",V2n,V2d);
	printf("       |V3| = |%d/%d|\n\n",V3n,V3d);
}

void eiPrint() {

	 printf("|%d/%d  %d/%d  %d/%d|    |x| = |%d|\n", u11n, u11d, u12n, u12d, u13n, u13d, V1);
	 printf("| 0   %d/%d  %d/%d|    |y| = |%d/%d|\n", u22n, u22d, u23n, u23d,V2n, V2d);
	 printf("| 0    0   %d/%d|    |z| = |%d/%d|\n\n", u33n, u33d, V3n, V3d);
	
}

void niPrint() {
	f_cal(V3n, V3d, '/',u33n, u33d );
	printf("  z=%d/%d",num3, den3);
	
	int tnum=num3;
	int tden=den3;
	
	f_cal(num3,den3,'*',u23n, u23d);
	f_cal(V2n, V2d, '-', num3, den3);
	f_cal(num3,den3,'/', u22n, u22d);
	printf("\n  y=%d/%d",num3, den3);
	
	f_cal(num3,den3,'*',u12n, u12d);
	f_cal(V1,1,'-',num3,den3);
	f_cal(num3, den3, '-', tnum*u13n, tden*u13d);
	f_cal(num3, den3, '/', u11n, u11d);
	printf("\n  x=%d/%d",num3, den3);
}

void calc() {
	u11n=x1;
	u12n=y1;
	u13n=z1;
	printf("First Row :\nu11=x1 => %d\nu12=y1 => %d\nu13=z1 => %d",u11n,u12n,u13n);
	printf("\n\n");
	
	//l21
	f_cal(x2,1,'/',u11n,u11d);
	printf("First Column :\nl21=x2/u11 => %d/%d",num3, den3);
	l21n=num3;
	l21d=den3;
	
	
	//l31		
	f_cal(x3,1,'/',u11n,u11d);
	printf("\nl31=x3/u11 => %d/%d",num3, den3);
    l31n=num3;
	l31d=den3;
	
		
	printf("\n\n");
	
	//u22
	f_cal(l21n,l21d,'*',u12n,u12d);
	f_cal(y2,1,'-',num3,den3);
	u22n=num3;
	u22d=den3;
	printf("Second Row :\nu22=y2-(l21*u12) => %d/%d",u22n,u22d);
	
	//u23
	f_cal(l21n,l21d,'*',u13n,u13d);
	f_cal(z2,1,'-',num3,den3);
	u23n=num3;
	u23d=den3;
	printf("\nu23=z2-(l21*u13) => %d/%d",u23n, u23d);
	printf("\n\n");
	
	//l32
	f_cal(l31n,l31d,'*',u12n,u12d);
	f_cal(y3,1,'-',num3,den3);
	f_cal(num3,den3,'/',u22n,u22d);
	l32n=num3;
	l32d=den3;
	printf("Second Column : l32=(y3-(l31*u12))/u22 => %d/%d",l32n,l32d);
	printf("\n\n");
	
	//u23
	f_cal(l31n,l31d,'*',u13n,u13d);
	f_cal(z3,1,'-',num3,den3);
	int tnum=num3;
	int tden=den3;
	f_cal(l32n,l32d,'*',u23n,u23d);	
	f_cal(tnum,tden,'-',num3,den3);
	u33n=num3;
	u33d=den3;	
	printf("Third Row : u33=z3-(l31*u13)-(l32*u23) => %d/%d",u33n,u33d);
}

int main()
{
	//scan();
	set1();
	//set2();
	
	printf("The System of Linear Equations can be written as :");
	printf("\n\n");
	fPrint();
	printf("\t:.AX = B - (1)");
	printf("\n\n");
	printf("by L-U Decomposition Method,");
	printf("\n\t  A = LU");
	printf("\n\n");
	sPrint();
	tPrint();
	calc();
	printf("\n\n\nNow,\n\n");
	foPrint();
	printf("\t  :.A = LU\n\n");
	printf(" From (1),\n    LUX = B - (2)");
	printf("\n\n");
	printf("\nPut UX = V, where V =|V1|\n");
	printf("                     |V2|\n");
	printf("                     |V3|");
	printf("\n\n");
	printf("From (2), LV =B");
	printf("\n\n");
	fiPrint();
	siPrint();
	printf("Now, Evaluate the Values of all V's");
	printf("\n\n");
	V1=d1;
	printf("  V1 = %d",d1);
	
	int tnum=V1*l21n;
	int tden=l21d;
	f_cal(d2,1,'-',tnum,tden);
	V2n=num3;
	V2d=den3;
	printf("\n  V2 = %d/%d",V2n, V2d);
	
	tnum=V1*l31n;
	tden=l31d;
	f_cal(d3,1,'-',tnum,tden);
	
	tnum=V2n*l32n;
	tden=l32d*V2d;
	f_cal(num3,den3,'-',tnum,tden);
	
	V3n=num3;
	V3d=den3;
	printf("\n  V3 = %d/%d",V3n, V3d);
	
	printf("\n\n");
	
	sePrint();
	
	printf("Now, we have -> UX=V");
	
	printf("\n\n");
	
	eiPrint();
	
	printf("Calculating the Values of x,y,z:");
	printf("\n\n");
	
	niPrint();
	
	printf("\n\nArt by Deepak - dk -");	
}
