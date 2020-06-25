/**************************************************/
/*
Author: Amgad Samir
File Name: BIT_MATH.h
Component: BitWise Function Like Macros
Version:1.0
 */
/**************************************************/

#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(VAR,BIT_NB) (VAR)|=(1<<(BIT_NB))
#define CLR_BIT(VAR,BIT_NB) (VAR)&=~(1<<(BIT_NB))
#define TOGGLE_BIT(VAR,BIT_NB) (VAR)^=(1<<(BIT_NB))
#define ASSIGN_BIT(VAR,BIT_NB,VAL) VAR=(VAR&(~(1<<BIT_NB)))|(VAL<<BIT_NB)
#define GET_BIT(VAR,BIT_NB) ((VAR>>BIT_NB)&0x01)


#endif /* BIT_MATH_H_ */
