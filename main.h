/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.h
 * Author: Hakeem
 *
 * Created on 24 November 2017, 14:57
 */

#ifndef MAIN_H
#define MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

    
    void doExperiment(int n, int k, FILE* log);
    void doOptimisationComparison(int n, int k, FILE* log);
    void main();


#ifdef __cplusplus
}
#endif

#endif /* MAIN_H */

