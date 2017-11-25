/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Hakeem
 *
 * Created on 22 November 2017, 17:41
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "main.h"
#include "series.h"
#include "subseriesMatcher.h"

void doExperiment(int n, int k, FILE* log){

    MAX_RANDOM_VALUE = 10;
    SeriesList* list = newSeriesList();
    //populates list as an n*n list of series
    randomlyPopulateSeriesList(n, list);
    Series* lookingFor = newSeries();
    randomlyPopulateSeries(k, lookingFor);
    
    clock_t start, end;
    double duration;
    
    start = clock();
    Result* result = subseriesMatching(lookingFor, list);
    end = clock();
    duration = (end - start) / CLOCKS_PER_SEC;
    
    printf("n=%d,k=%d,duration=%lf,distance=%lf\n", n, k, duration, result->distance);
    fprintf(log, "%d,%d,%lf,%lf\r\n", n, k, duration, result->distance);
    
}

void main() {
    printf("Running timing experiment...\n\n");
    
    FILE* log = fopen("subseries_search_timing_experiment.csv", "w");
    fprintf(log, "n,k,duration,distance\r\n");
    
    if (log == NULL){
        fprintf(stderr, "Failed to open log file.\r\n");
        exit(EXIT_FAILURE);
    }
    
    const int LIST_UPPER_LIMIT = 3000;
    const int LIST_STEP = 500;
    const int TARGET_SERIES_LIMIT = 10;
    const int TARGET_SERIES_STEP = 2;
    
    for (int k = 1; k < TARGET_SERIES_LIMIT; k=k+TARGET_SERIES_STEP){
        for (int n = 0; n < LIST_UPPER_LIMIT; n=n+LIST_STEP){
            
            //if n < k, then just use the value of k for that run (e.g. the minimum length the list of series can be, given length of the subseries to match).
            doExperiment((n<k)? k:n, k, log);
        }
    }
    
    printf("See subseries_search_timing_experiment.log for results.\n");
    exit(EXIT_SUCCESS);
}



