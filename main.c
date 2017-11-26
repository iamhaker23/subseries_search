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

void doOptimisationComparison(int n, int k, FILE* log){

    
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
    duration = (double)(end - start) / (double)CLOCKS_PER_SEC;
    
    printf("n=%d,k=%d,duration=%lf,distance=%lf,algo=%d\n", n, k, duration, result->distance, 0);
    fprintf(log, "%d,%d,%lf,%lf,%d\r\n", n, k, duration, result->distance, 0);
    fflush(log);
    
        start = clock();
        result = subseriesMatching(lookingFor, list);
        end = clock();
        duration = (double)(end - start) / (double)CLOCKS_PER_SEC;

        printf("n=%d,k=%d,duration=%lf,distance=%lf,algo=%d\n", n, k, duration, result->distance, 0);
        fprintf(log, "%d,%d,%lf,%lf,%d\r\n", n, k, duration, result->distance, 0);
        fflush(log);
        
        start = clock();
        result = subseriesMatching(lookingFor, list);
        end = clock();
        duration = (double)(end - start) / (double)CLOCKS_PER_SEC;

        printf("n=%d,k=%d,duration=%lf,distance=%lf,algo=%d\n", n, k, duration, result->distance, 0);
        fprintf(log, "%d,%d,%lf,%lf,%d\r\n", n, k, duration, result->distance, 0);
        fflush(log);
    
    start = clock();
    result = subseriesMatching_w_optimisation_1(lookingFor, list);
    end = clock();
    duration = (double)(end - start) / (double)CLOCKS_PER_SEC;
    
    printf("n=%d,k=%d,duration=%lf,distance=%lf,algo=%d\n", n, k, duration, result->distance, 1);
    fprintf(log, "%d,%d,%lf,%lf,%d\r\n", n, k, duration, result->distance, 1);
    fflush(log);
    
        start = clock();
        result = subseriesMatching_w_optimisation_1(lookingFor, list);
        end = clock();
        duration = (double)(end - start) / (double)CLOCKS_PER_SEC;

        printf("n=%d,k=%d,duration=%lf,distance=%lf,algo=%d\n", n, k, duration, result->distance, 1);
        fprintf(log, "%d,%d,%lf,%lf,%d\r\n", n, k, duration, result->distance, 1);
        fflush(log);

        start = clock();
        result = subseriesMatching_w_optimisation_1(lookingFor, list);
        end = clock();
        duration = (double)(end - start) / (double)CLOCKS_PER_SEC;

        printf("n=%d,k=%d,duration=%lf,distance=%lf,algo=%d\n", n, k, duration, result->distance, 1);
        fprintf(log, "%d,%d,%lf,%lf,%d\r\n", n, k, duration, result->distance, 1);
        fflush(log);
    
    start = clock();
    result = subseriesMatching_w_optimisation_2(lookingFor, list);
    end = clock();
    duration = (double)(end - start) / (double)CLOCKS_PER_SEC;
    
    printf("n=%d,k=%d,duration=%lf,distance=%lf,algo=%d\n", n, k, duration, result->distance, 2);
    fprintf(log, "%d,%d,%lf,%lf,%d\r\n", n, k, duration, result->distance, 2);
    fflush(log);
    
        start = clock();
        result = subseriesMatching_w_optimisation_2(lookingFor, list);
        end = clock();
        duration = (double)(end - start) / (double)CLOCKS_PER_SEC;

        printf("n=%d,k=%d,duration=%lf,distance=%lf,algo=%d\n", n, k, duration, result->distance, 2);
        fprintf(log, "%d,%d,%lf,%lf,%d\r\n", n, k, duration, result->distance, 2);
        fflush(log);

        start = clock();
        result = subseriesMatching_w_optimisation_2(lookingFor, list);
        end = clock();
        duration = (double)(end - start) / (double)CLOCKS_PER_SEC;

        printf("n=%d,k=%d,duration=%lf,distance=%lf,algo=%d\n", n, k, duration, result->distance, 2);
        fprintf(log, "%d,%d,%lf,%lf,%d\r\n", n, k, duration, result->distance, 2);
        fflush(log);
    
    /*start = clock();
    result = subseriesMatching_w_optimisation_3(lookingFor, list);
    end = clock();
    duration = (double)(end - start) / (double)CLOCKS_PER_SEC;
    
    printf("n=%d,k=%d,duration=%lf,distance=%lf,algo=%d\n", n, k, duration, result->distance, 3);
    fprintf(log, "%d,%d,%lf,%lf,%d\r\n", n, k, duration, result->distance, 3);
    fflush(log);*/
    
    start = clock();
    result = subseriesMatching_w_optimisation_4(lookingFor, list);
    end = clock();
    duration = (double)(end - start) / (double)CLOCKS_PER_SEC;
    
    printf("n=%d,k=%d,duration=%lf,distance=%lf,algo=%d\n", n, k, duration, result->distance, 4);
    fprintf(log, "%d,%d,%lf,%lf,%d\r\n", n, k, duration, result->distance, 4);
    fflush(log);
    
        start = clock();
        result = subseriesMatching_w_optimisation_4(lookingFor, list);
        end = clock();
        duration = (double)(end - start) / (double)CLOCKS_PER_SEC;

        printf("n=%d,k=%d,duration=%lf,distance=%lf,algo=%d\n", n, k, duration, result->distance, 4);
        fprintf(log, "%d,%d,%lf,%lf,%d\r\n", n, k, duration, result->distance, 4);
        fflush(log);
        
        start = clock();
        result = subseriesMatching_w_optimisation_4(lookingFor, list);
        end = clock();
        duration = (double)(end - start) / (double)CLOCKS_PER_SEC;

        printf("n=%d,k=%d,duration=%lf,distance=%lf,algo=%d\n", n, k, duration, result->distance, 4);
        fprintf(log, "%d,%d,%lf,%lf,%d\r\n", n, k, duration, result->distance, 4);
        fflush(log);
    
}

void main() {
    printf("Running timing experiment...\n\n");
    
    FILE* log = NULL;
    
    //char mode = 'a';
    char mode = 'b';
    
    const int LIST_UPPER_LIMIT = 3000;
    const int LIST_STEP = 500;
    const int TARGET_SERIES_LIMIT = 10;
    const int TARGET_SERIES_STEP = 2;
    
    switch(mode){
        case 'a':
            
            log = fopen("subseries_search_timing_experiment.csv", "w");
            fprintf(log, "n,k,duration,distance\r\n");

            if (log == NULL){
                fprintf(stderr, "Failed to open log file.\r\n");
                exit(EXIT_FAILURE);
            }
            
            MAX_RANDOM_VALUE = 500;
            
            for (int k = 1; k < TARGET_SERIES_LIMIT; k=k+TARGET_SERIES_STEP){
                for (int n = 0; n < LIST_UPPER_LIMIT; n=n+LIST_STEP){

                    //if n < k, then just use the value of k for that run (e.g. the minimum length the list of series can be, given length of the subseries to match).
                    doExperiment((n<k)? k:n, k, log);
                }
            }
            break;
        case 'b':
            
            log = fopen("subseries_search_timing_experiment.csv", "w");
            fprintf(log, "n,k,duration,distance,algo\r\n");
            
            MAX_RANDOM_VALUE = 2500;
            int k = 1;
            
            for (int n = 0; n < 3500; n=n+1000){

                //if n < k, then just use the value of k for that run (e.g. the minimum length the list of series can be, given length of the subseries to match).
                doOptimisationComparison((n<k)? k:n, k, log);
            }
            
            break;
        case 'c':
            //Fails to show time-complexity improvement by attempting to reduce the candidate set size on each iteration
            
            log = fopen("subseries_search_timing_experiment.csv", "w");
            fprintf(log, "n,k,duration,distance,algo\r\n");
            
            int specialCaseN = 1000;
            int specialCaseK = 1;
            MAX_RANDOM_VALUE = 5000;
            
            SeriesList* list = newSeriesList();
            //populates list as an n*n list of series
            randomlyPopulateSeriesList(specialCaseN, list);
            Series* lookingFor = newSeries();
            randomlyPopulateSeries(specialCaseK, lookingFor);

            printf("Generated random input: looking for %dB in series list %dMB\n", (lookingFor->length * sizeof(Element)), (list->length*list->length*sizeof(SNode))/(1024*1024));
            
            clock_t start, end;
            double duration;

            start = clock();
            Result* result = subseriesMatching(lookingFor, list);
            end = clock();
            duration = (double)(end - start) / (double)CLOCKS_PER_SEC;

            printf("n=%d,k=%d,duration=%lf,distance=%lf,algo=%d,result=%d:%d:%d\n", specialCaseN, specialCaseK, duration, result->distance, 0, result->seriesIndex, result->startOfSequenceIndex, result->lengthOfMatch);
            fprintf(log, "%d,%d,%lf,%lf,%d\r\n", specialCaseN, specialCaseK, duration, result->distance, 0);
            fflush(log);

            start = clock();
            result = subseriesMatching_w_optimisation_4(lookingFor, list);
            end = clock();
            duration = (double)(end - start) / (double)CLOCKS_PER_SEC;

            printf("n=%d,k=%d,duration=%lf,distance=%lf,algo=%d,result=%d:%d:%d\n", specialCaseN, specialCaseK, duration, result->distance, 4, result->seriesIndex, result->startOfSequenceIndex, result->lengthOfMatch);
            fprintf(log, "%d,%d,%lf,%lf,%d\r\n", specialCaseN, specialCaseK, duration, result->distance, 4);
            fflush(log);
            
            //regenerate the search list and use the baked cache
            
            freeSeriesList(list);
            SeriesList* list2 = newSeriesList();
            randomlyPopulateSeriesList(specialCaseN, list2);
            
            start = clock();
            result = subseriesMatching(lookingFor, list2);
            end = clock();
            duration = (double)(end - start) / (double)CLOCKS_PER_SEC;

            printf("n=%d,k=%d,duration=%lf,distance=%lf,algo=%d,result=%d:%d:%d\n", specialCaseN, specialCaseK, duration, result->distance, 0, result->seriesIndex, result->startOfSequenceIndex, result->lengthOfMatch);
            fprintf(log, "%d,%d,%lf,%lf,%d\r\n", specialCaseN, specialCaseK, duration, result->distance, 0);
            fflush(log);
            
            start = clock();
            result = subseriesMatching_w_optimisation_4(lookingFor, list2);
            end = clock();
            duration = (double)(end - start) / (double)CLOCKS_PER_SEC;

            printf("n=%d,k=%d,duration=%lf,distance=%lf,algo=%d,result=%d:%d:%d\n", specialCaseN, specialCaseK, duration, result->distance, 4, result->seriesIndex, result->startOfSequenceIndex, result->lengthOfMatch);
            fprintf(log, "%d,%d,%lf,%lf,%d\r\n", specialCaseN, specialCaseK, duration, result->distance, 4);
            fflush(log);
            
            break;
        case 'd':
            
            log = fopen("subseries_search_timing_experiment.csv", "w");
            fprintf(log, "n,k,memory,distance,algo\r\n");
            
            specialCaseN = 1000;
            specialCaseK = 40;
            
            list = newSeriesList();
            //populates list as an n*n list of series
            randomlyPopulateSeriesList(specialCaseN, list);
            lookingFor = newSeries();
            randomlyPopulateSeries(specialCaseK, lookingFor);

            start, end;
            duration;

            start = clock();
            result = subseriesMatching_log_mem(lookingFor, list, log);
            end = clock();
            duration = (double)(end - start) / (double)CLOCKS_PER_SEC;

            printf("n=%d,k=%d,duration=%lf,distance=%lf,algo=%d\n", specialCaseN, specialCaseK, duration, result->distance, 0);

            start = clock();
            result = subseriesMatching_log_mem_optimisation_6(lookingFor, list, log);
            end = clock();
            duration = (double)(end - start) / (double)CLOCKS_PER_SEC;

            printf("n=%d,k=%d,duration=%lf,distance=%lf,algo=%d\n", specialCaseN, specialCaseK, duration, result->distance, 4);
            
            break;
        default:
            break;
    }
    
    
    printf("See subseries_search_timing_experiment.log for results.\n");
    exit(EXIT_SUCCESS);
}



