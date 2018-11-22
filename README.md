# Gas Crisis

  
  
Mr Smith is in love and he plans to visit the owner of his heart, Miss Wesson. But he is also avaricious, gas is expensive and the travel has to be as cheap as possible, because, as he says to his friend Mr Beretta, "money is for bread and roses, not for gas ". Thus he has to plan very carefully in which gas stations he has to stop. Your goal is to help him to find the cheapest route.  

## Problem

Because of its avarice, Mr Smith believes that he has to drive very smoothly in order to get the lowest consumption (liters of gas per 100 kilometers). As a matter of fact, during his travels by car, he obtains a constant one, say ![$C$](http://tiup.ubi.pt/~mooshak/cgi-bin/execute/5857920411908031?image+A+img2.png) liters of gas per 100 kilometers. Consider that the capacity of Mr Smith's car tank is ![$L$](http://tiup.ubi.pt/~mooshak/cgi-bin/execute/5857920411908031?image+A+img3.png) liters.

Miss Wesson lives ![$d$](http://tiup.ubi.pt/~mooshak/cgi-bin/execute/5857920411908031?image+A+img4.png) kilometers from Mr Smith and there are ![$n$](http://tiup.ubi.pt/~mooshak/cgi-bin/execute/5857920411908031?image+A+img5.png) gas stations along the way. They are numbered from ![$0$](http://tiup.ubi.pt/~mooshak/cgi-bin/execute/5857920411908031?image+A+img6.png) to ![$n-1$](http://tiup.ubi.pt/~mooshak/cgi-bin/execute/5857920411908031?image+A+img7.png). Suppose, for the sake of simplicity, that n is less or equal to 100. For a gas station, say ![$i$](http://tiup.ubi.pt/~mooshak/cgi-bin/execute/5857920411908031?image+A+img8.png), the price of the gas per liter is ![$p_i$](http://tiup.ubi.pt/~mooshak/cgi-bin/execute/5857920411908031?image+A+img9.png), and the distance to the next gas station is ![$d_i$](http://tiup.ubi.pt/~mooshak/cgi-bin/execute/5857920411908031?image+A+img10.png). Assume that for all ![$i$](http://tiup.ubi.pt/~mooshak/cgi-bin/execute/5857920411908031?image+A+img8.png) and ![$j$](http://tiup.ubi.pt/~mooshak/cgi-bin/execute/5857920411908031?image+A+img11.png) ( ![$0\leq i,j \leq n-1 $](http://tiup.ubi.pt/~mooshak/cgi-bin/execute/5857920411908031?image+A+img12.png)), ![$i\not = j$](http://tiup.ubi.pt/~mooshak/cgi-bin/execute/5857920411908031?image+A+img13.png) implies that ![$d_i \not = d_j$](http://tiup.ubi.pt/~mooshak/cgi-bin/execute/5857920411908031?image+A+img14.png) (all the ![$d_i$](http://tiup.ubi.pt/~mooshak/cgi-bin/execute/5857920411908031?image+A+img10.png)s are distinct). The distance between the last gas station and Miss Wesson's house is ![$d_{n-1}$](http://tiup.ubi.pt/~mooshak/cgi-bin/execute/5857920411908031?image+A+img15.png). Suppose that for all ![$i$](http://tiup.ubi.pt/~mooshak/cgi-bin/execute/5857920411908031?image+A+img8.png) such that ![$0\leq i \leq n-1$](http://tiup.ubi.pt/~mooshak/cgi-bin/execute/5857920411908031?image+A+img16.png), ![$d_i$](http://tiup.ubi.pt/~mooshak/cgi-bin/execute/5857920411908031?image+A+img10.png) is greater than ![$0$](http://tiup.ubi.pt/~mooshak/cgi-bin/execute/5857920411908031?image+A+img6.png). We then have ![$d=\sum^{n-1}_{i=0} d_i$](http://tiup.ubi.pt/~mooshak/cgi-bin/execute/5857920411908031?image+A+img17.png).

Suppose that Mr Smith's car tank is empty at the beginning of the travel and that it is parked beside the first of these gas stations (the gas station ![$0$](http://tiup.ubi.pt/~mooshak/cgi-bin/execute/5857920411908031?image+A+img6.png) is the starting point). Assume that all the prices are distinct (there is no two gas stations offering the same price).

In a picture, the situation is the following:

> ----------
> 
> ![](http://tiup.ubi.pt/~mooshak/cgi-bin/execute/5857920411908031?image+A+gasolina001.gif)  
> 
> Figure 1: The Mr Smith's travel map
> 
>   
> 
> ----------

Your work is to establish in which gas stations he has to stop and how many liters of gas he has to fill up in each of these stations in order to make the cheapest travel. Remember that, in such a situation, Mr Smith car reaches Miss Wesson's house with an empty tank.  

  

## Input

  

-   The first line of input contains a float denoting the consumption of the Smith's car (the value of _C_);
-   the second line of input contains an integer denoting the capacity of the car tank (the value of _L_);
-   the third line of input contains an integer denoting the number of gas stations (the value of _n_);
-   the next _n_ lines contain an integer and a float separated by a space. The _i__th_ line of these _n_ lines contains the information of the gas station (_i_-1), thus the first number represents the distance _d__i_-1 and the second represents _p__i_-1.

## Output

There are two kinds of output:

-   The first one is the output produced if there is no possible plan. In this case the output is a single line containing the word NO.  
      
    
-   In case of success, Mr Smith is able to draw a plan to visit Miss Wesson, and the output is organized as follow:  
      
    If Mr. Smith has to stop into _m_ gas stations, your program has to produce _m_ lines of output. Each of these lines is of the form:  
      
    i l
      
    where _i_ is an integer identifying a gas station (its number) and _l_ is the float denoting the quantity (in liters) of gas that Mr Smith took from this gas station. The numbers _i_ and _l_ are separated by a single space. Note that all the produced floating point numbers **must have exactly** two decimal digits.  
      
    These lines are ordered increasingly by the identification of the gas station.

  

## First Sample Input  

7.8  
30  
5  
170 0.49  
100 0.42  
150 0.52  
120 0.53  
50 0.57  

## First Sample Output  

0 13.26  
1 30.00  
2 2.76

## Second Sample Input  

8.8  
30  
3  
250 0.50  
350 0.55  
220 0.45  

## Second Sample Output  

NO
