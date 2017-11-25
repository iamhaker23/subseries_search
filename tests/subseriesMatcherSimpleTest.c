/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   subseriesMatcherSimpleTest.c
 * Author: Hakeem
 *
 * Created on 24 November 2017, 10:08
 */

#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <math.h>

#include "series.h"
#include "subseriesMatcher.h"

/*
 * Simple C Test Suite
 */

void testSubseriesMatcher() {
    
    Series* series = newSeries();
    Series* series2 = newSeries();
    SeriesList* seriesList = newSeriesList();
    
    //add 10 series to the list to ensure n*n dimensions
    appendToSeriesList(series, seriesList);
    appendToSeriesList(series2, seriesList);
    appendToSeriesList(series2, seriesList);
    appendToSeriesList(series2, seriesList);
    appendToSeriesList(series2, seriesList);
    appendToSeriesList(series2, seriesList);
    appendToSeriesList(series2, seriesList);
    appendToSeriesList(series2, seriesList);
    appendToSeriesList(series2, seriesList);
    appendToSeriesList(series2, seriesList);
    
    appendToSeries(1, series);
    appendToSeries(2, series);
    appendToSeries(3, series);
    appendToSeries(4, series);
    appendToSeries(5, series);
    appendToSeries(6, series);
    appendToSeries(7, series);
    appendToSeries(8, series);
    appendToSeries(9, series);
    appendToSeries(10, series);
    
    appendToSeries(1, series2);
    appendToSeries(2, series2);
    appendToSeries(3, series2);
    appendToSeries(4, series2);
    appendToSeries(5, series2);
    appendToSeries(6, series2);
    appendToSeries(7, series2);
    appendToSeries(8, series2);
    appendToSeries(9, series2);
    appendToSeries(100, series2);
    
    
    Series* lookingFor = newSeries();
    appendToSeries(8, lookingFor);
    appendToSeries(9, lookingFor);
    appendToSeries(10, lookingFor);
    
    Series* distanceA = newSeries();
    appendToSeries(5, distanceA);
    appendToSeries(6, distanceA);
    appendToSeries(7, distanceA);
    
    Series* distanceB = newSeries();
    appendToSeries(5, distanceB);
    appendToSeries(8, distanceB);
    appendToSeries(7, distanceB);
    
    double d = distance(distanceA, distanceB);
    
    if (d != 2.0f){
        printf("%%TEST_FAILED%% time=0 testname=testSubseriesMatcher (subseriesMatcherSimpleTest) message=Expected distance of 2.0f, got %lf\n", d);
    }
    
    //adds 25 to the sqaure of the distance
    appendToSeries(10, distanceA);
    appendToSeries(15, distanceB);
    
    d = distance(distanceA, distanceB);
    
    if ((fabs(d) - fabs(5.385165f)) > DBL_MIN){
        printf("%%TEST_FAILED%% time=0 testname=testSubseriesMatcher (subseriesMatcherSimpleTest) message=Expected distance of sqrt(29.0f), got %f\n", d);
    }
    
    printf("Printing series list:\n");
    printSeriesList(seriesList);
    printf("Printing series to look for:\n");
    printSeries(lookingFor);
    
    Result* result = subseriesMatching(lookingFor, seriesList);
    if (result->lengthOfMatch != 3){
        printf("%%TEST_FAILED%% time=0 testname=testSubseriesMatcher (subseriesMatcherSimpleTest) message=Expected length of match 3, got %d\n", result->lengthOfMatch);
    }
    if (result->seriesIndex != 0){
        printf("%%TEST_FAILED%% time=0 testname=testSubseriesMatcher (subseriesMatcherSimpleTest) message=Expected match in series 0, got %d\n", result->seriesIndex);
    }
    
    if (result->startOfSequenceIndex != 7){
        printf("%%TEST_FAILED%% time=0 testname=testSubseriesMatcher (subseriesMatcherSimpleTest) message=Expected match at index 4, got %d\n", result->startOfSequenceIndex);
    }
    if (result->distance != 0.0f){
        printf("%%TEST_FAILED%% time=0 testname=testSubseriesMatcher (subseriesMatcherSimpleTest) message=Expected Euclid distance of 0.0, got %lf\n", result->distance);
    }
    
}

int main(int argc, char** argv) {
    printf("%%SUITE_STARTING%% subseriesMatcherSimpleTest\n");
    printf("%%SUITE_STARTED%%\n");
    
    printf("%%TEST_STARTED%% testSubseriesMatcher (subseriesMatcherSimpleTest)\n");
    testSubseriesMatcher();
    printf("%%TEST_FINISHED%% time=0 testSubseriesMatcher (subseriesMatcherSimpleTest) \n");

    printf("%%SUITE_FINISHED%% time=0\n");

    return (EXIT_SUCCESS);
}
