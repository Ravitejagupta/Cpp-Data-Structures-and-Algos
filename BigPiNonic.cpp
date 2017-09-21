#include <iostream>
#include <iomanip>
#include <mpir.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

const int MAX_ITERATIONS = 100;
const int PLACES         = 1000;        // desired decimal places
const int PRECISION      = PLACES + 1;  // +1 for the digit 3 before the decimal

const int BASE       = 10;  // base 10 numbers
const int BIT_COUNT  = 8;   // bits per machine word

const int BLOCK_SIZE = 10;                // print digits in blocks
const int LINE_SIZE  = 100;               // digits to print per line
const int LINE_COUNT = PLACES/LINE_SIZE;  // lines to print
const int GROUP_SIZE = 5;                 // line grouping size

/**
 * Compute the cube root of a positive integer.
 * @param x where to store the result.
 * @param a the number whose cube root to compute.
 */
void cube_root(mpf_t& x, const mpf_t a);
void cube_root1(mpf_t& x, const mpf_t a);

/***** Add more functions as necessary. *****/

/**
 * The main.
 */
int main()
{
    mpf_set_default_prec(BIT_COUNT*PRECISION*2);  // precision in bits

    mpf_t pi; mpf_init(pi);
	
	
    /***** Complete this main. *****/
	
	mpf_t one;
	mpf_init(one);
	mpf_set_d(one,1);	

	mpf_t three;
	mpf_init(three);
	mpf_set_d(three,3);
	
	mpf_t two;
	mpf_init(two);
	mpf_set_d(two,2);

	mpf_t nine;
	mpf_init(nine);
	mpf_set_d(nine,9);

	mpf_t twentyseven;
	mpf_init(twentyseven);
	mpf_set_d(twentyseven,27);

	mpf_t a;
    	mpf_init(a);
	mpf_div(a,one,three);

//			gmp_printf("A   %.Ff",a); cout<<endl;

	mpf_t half;
	mpf_init(half);
	mpf_div(half,one,two);
	
	mpf_t root3;
	mpf_init(root3);
	mpf_sqrt(root3, three);

	mpf_t root3minus1;
	mpf_init(root3minus1);
	mpf_sub(root3minus1, root3, one);

	mpf_t r;
	mpf_init(r);
	mpf_div(r, root3minus1, two);

	//		gmp_printf("R   %.Ff",r); cout<<endl;

	mpf_t rcube;
	mpf_init(rcube);
	mpf_pow_ui(rcube,r,3);
			
//				gmp_printf("rcube   %.Ff",rcube); cout<<endl;

	mpf_t oneminusrcube;
	mpf_init(oneminusrcube);
	mpf_sub(oneminusrcube,one,rcube);
		
//				gmp_printf("oneminusrcube   %.Ff",oneminusrcube); cout<<endl;	

	mpf_t s;
	mpf_init(s);

	cube_root1(s,oneminusrcube);

//			gmp_printf("S   %.Ff",s); cout<<endl;

	/** For Iterations **/

	mpf_t t,u,v,w;
	mpf_init(t);mpf_init(u);mpf_init(v);mpf_init(w);

	for(int j=0;j<=100;j++){
	
	//t

	mpf_t twor;
	mpf_init(twor);
	mpf_mul(twor,two,r);

	mpf_add(t,one,twor);


	//u

	mpf_t niner;
	mpf_init(niner);
	mpf_mul(niner,nine,r);

	mpf_t rsquare;
	mpf_init(rsquare);
	mpf_pow_ui(rsquare,r,2);

	mpf_t oneplusr;
	mpf_init(oneplusr);
	mpf_add(oneplusr,r,one);

	mpf_t oneplusrplusrsquare;
	mpf_init(oneplusrplusrsquare);
	mpf_add(oneplusrplusrsquare,oneplusr,rsquare);

	mpf_t nineroneplusrplusrsquare;
	mpf_init(nineroneplusrplusrsquare);
	mpf_mul(nineroneplusrplusrsquare,oneplusrplusrsquare,niner);

	cube_root1(u,nineroneplusrplusrsquare);


	//v
	
	mpf_t tsquare;
	mpf_init(tsquare);
	mpf_pow_ui(tsquare,t,2);

	mpf_t usquare;
	mpf_init(usquare);
	mpf_pow_ui(usquare,u,2);

	mpf_t tu;
	mpf_init(tu);
	mpf_mul(tu,t,u);

	mpf_t tuplustsquare;
	mpf_init(tuplustsquare);
	mpf_add(tuplustsquare,tu,tsquare);

	mpf_add(v,tuplustsquare,usquare);


	//w

	mpf_t ssquare;
	mpf_init(ssquare);
	mpf_pow_ui(ssquare,s,2);

	mpf_t onepluss;
	mpf_init(onepluss);
	mpf_add(onepluss,one,s);
	
	mpf_t oneplussplussquare;
	mpf_init(oneplussplussquare);
	mpf_add(oneplussplussquare,onepluss,ssquare);

	mpf_t twentysevenoneplussplussquare;
	mpf_init(twentysevenoneplussplussquare);
	mpf_mul(twentysevenoneplussplussquare,oneplussplussquare,twentyseven);

	mpf_div(w,twentysevenoneplussplussquare,v);


	//a

	mpf_t wa;
	mpf_init(wa);
	mpf_mul(wa,w,a);
	
	mpf_t oneminusw;
	mpf_init(oneminusw);
	mpf_sub(oneminusw,one,w);

	mpf_t i;
	mpf_init(i);
	mpf_set_d(i,j);

	mpf_t twoi;
	mpf_init(twoi);
	mpf_mul(twoi,two,i);
	

	mpf_t twoiminusone;
	mpf_init(twoiminusone);
	mpf_sub(twoiminusone,twoi,one);

	int z;
	z = mpf_get_si(twoiminusone);

	mpf_t threextwonminus1;
	mpf_init(threextwonminus1);

	if(z>=0)
	mpf_pow_ui(threextwonminus1,three,z);
	else
	mpf_div(threextwonminus1,one,three);

	mpf_t threextwonminus1intooneminusw;
	mpf_init(threextwonminus1intooneminusw);
	mpf_mul(threextwonminus1intooneminusw,threextwonminus1,oneminusw);


	mpf_add(a,wa,threextwonminus1intooneminusw);

//			gmp_printf("A   %.Ff",a); cout<<endl;

	//s

	mpf_t oneminusr;
	mpf_init(oneminusr);
	mpf_sub(oneminusr,one,r);

	mpf_t oneminusrcube;
	mpf_init(oneminusrcube);
	mpf_pow_ui(oneminusrcube,oneminusr,3);

	mpf_t twou;
	mpf_init(twou);
	mpf_mul(twou,u,two);

	mpf_t tplustwou;
	mpf_init(tplustwou);
	mpf_add(tplustwou,twou,t);

	mpf_t tplustwouv;
	mpf_init(tplustwouv);
	mpf_mul(tplustwouv,tplustwou,v);

	mpf_div(s,oneminusrcube,tplustwouv);

//			gmp_printf("S   %.Ff",s); cout<<endl;

	//r

	mpf_t scube;
	mpf_init(scube);
	mpf_pow_ui(scube,s,3);

	mpf_t oneminusscube;
	mpf_init(oneminusscube);
	mpf_sub(oneminusscube,one,scube);

	cube_root1(r,oneminusscube);

//	gmp_printf("R  %.Ff",r); cout<<endl;
	
	
}	
	mpf_div(pi,one,a);
//	gmp_printf ("Here is the Pi value %.1000 Ff", pi);
	
	char *pi_val = (char *) malloc(1002*sizeof(char));     // No of digits to be printed.
    	mp_exp_t power;

    	mpf_get_str(pi_val, &power, 10, 1001, pi);

    cout << pi_val[0] << "." ;                             

    for ( int i = 0; i < PLACES; i++)			    // Iterate for 1000 values
    {
	if(i % BLOCK_SIZE == 0 && i != 0)
	    cout << " ";

	if(i % LINE_SIZE == 0 && i != 0)
            cout << endl << "  ";
	
	if(i % (GROUP_SIZE * LINE_SIZE) == 0 && i != 0)
            cout << endl << "  ";
  
        cout << pi_val[i+1];
    }
    cout << endl;
 
    return 0;
}

void cube_root1(mpf_t& xn, const mpf_t a)
{

	//cout<<"Finding cube root"<<endl;
	mpf_t three;
    mpf_init(three);
    mpf_set_d(three, 3);

    mpf_t two;
    mpf_init(two);
    mpf_set_d(two, 2);
	
//	mpf_t x;
    mpf_init(xn);
    // intialized the xn with a / 3;
	mpf_div(xn, a, three);

	// xn+1 = xn *(xn3 * 2a/2*xn3+a)

	mpf_t twoa;
    mpf_init(twoa);
    mpf_mul(twoa, a, two);


	for(int i=0;i<=10;i++){


	    mpf_t xnpower3;
	    mpf_init(xnpower3);
	    mpf_pow_ui(xnpower3, xn, 3);

	    mpf_t twoxnpower3;
	    mpf_init(twoxnpower3);
	    mpf_mul(twoxnpower3, xnpower3, two);

	    mpf_t xnpower3add2a;
		mpf_init(xnpower3add2a);
		mpf_add(xnpower3add2a, xnpower3, twoa);

		mpf_t twoxnpower3plusa;
	    mpf_init(twoxnpower3plusa);
	    mpf_add(twoxnpower3plusa, twoxnpower3, a);

	    mpf_t secondPart;
	    mpf_init(secondPart);
	    mpf_div(secondPart, xnpower3add2a, twoxnpower3plusa);

	    mpf_t xnplus1;
	    mpf_init(xnplus1);
	    mpf_mul(xnplus1, xn, secondPart);

	    mpf_init_set(xn, xnplus1);

	}


    /***** Complete this function. *****/
}
