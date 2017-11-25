/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   seriesSimpleTest.c
 * Author: Hakeem
 *
 * Created on 22 November 2017, 17:56
 */

#include <stdio.h>
#include <stdlib.h>
#include "series.h"

/*
 * Simple C Test Suite
 */

void testSeriesStruct() {
    printf("seriesSimpleTest testSeriesStruct\n");
    
    Series* series = newSeries();
    
    if (series->length != 0){
        printf("%%TEST_FAILED%% time=0 testname=testSeriesStruct (seriesSimpleTest) message=error message sample\n");
    }
    
    appendToSeries(1, series);
    
    if (series->length != 1){
        printf("%%TEST_FAILED%% time=0 testname=testSeriesStruct (seriesSimpleTest) message=Expected length 1\n");
    }
    
    appendToSeries(100, series);
    
    if (series->length != 2){
        printf("%%TEST_FAILED%% time=0 testname=testSeriesStruct (seriesSimpleTest) message=Expected length 2\n");
    }
    
    appendToSeries(98, series);
    
    if (series->length != 3){
        printf("%%TEST_FAILED%% time=0 testname=testSeriesStruct (seriesSimpleTest) message=Expected length 3\n");
    }
    
    appendToSeries(64, series);
    appendToSeries(32, series);
    appendToSeries(108, series);
    
    if (series->length != 6){
        printf("%%TEST_FAILED%% time=0 testname=testSeriesStruct (seriesSimpleTest) message=Expected length 6\n");
    }
    
    
    if (series->first->value != 1 || series->first->index != 0 ){
        printf("%%TEST_FAILED%% time=0 testname=testSeriesStruct (seriesSimpleTest) message=Expected first element to be index 0, value 1.\n");
    }
    
    Element* test = getElement(1, series);
    if (test->value != 100 || test->index != 1){
        printf("%%TEST_FAILED%% time=0 testname=testSeriesStruct (seriesSimpleTest) message=Expected first element to be index 1, value 100.\n");
    }
    
    test = getElement(2, series);
    if (test->value != 98 || test->index != 2 ){
        printf("%%TEST_FAILED%% time=0 testname=testSeriesStruct (seriesSimpleTest) message=Expected first element to be index 2, value 98.\n");
    }
    
    test = getElement(3, series);
    if (test->value != 64 || test->index != 3 ){
        printf("%%TEST_FAILED%% time=0 testname=testSeriesStruct (seriesSimpleTest) message=Expected first element to be index 3, value 64.\n");
    }
    
    test = getElement(4, series);
    if (test->value != 32 || test->index != 4 ){
        printf("%%TEST_FAILED%% time=0 testname=testSeriesStruct (seriesSimpleTest) message=Expected first element to be index 4, value 32.\n");
    }
    
    test = getElement(5, series);
    if (test->value != 108 || test->index != 5 ){
        printf("%%TEST_FAILED%% time=0 testname=testSeriesStruct (seriesSimpleTest) message=Expected first element to be index 5, value 108.\n");
    }
    
    Series* slice = sliceSeries(series, 1, 4);
    if (slice->length != 4 ){
        printf("%%TEST_FAILED%% time=0 testname=testSeriesStruct (seriesSimpleTest) message=Expected slice of length 4.\n");
    }
    
    Element* sliceTest = getElement(0, slice);
    Element* originalTest = getElement(1, series);
    if (sliceTest->value != 100 || sliceTest->value != originalTest->value ){
        printf("%%TEST_FAILED%% time=0 testname=testSeriesStruct (seriesSimpleTest) message=Expected element 0, value 100 and equal to element 1 in series.\n");
    }
    
    sliceTest = getElement(1, slice);
    originalTest = getElement(2, series);
    if (sliceTest->value != 98 || sliceTest->value != originalTest->value ){
        printf("%%TEST_FAILED%% time=0 testname=testSeriesStruct (seriesSimpleTest) message=Expected element 1, value 98 and equal to element 2 in series.\n");
    }
    
    sliceTest = getElement(2, slice);
    originalTest = getElement(3, series);
    if (sliceTest->value != 64 || sliceTest->value != originalTest->value ){
        printf("%%TEST_FAILED%% time=0 testname=testSeriesStruct (seriesSimpleTest) message=Expected element 2, value 64 and equal to element 3 in series.\n");
    }
    
    sliceTest = getElement(3, slice);
    originalTest = getElement(4, series);
    if (sliceTest->value != 32 || sliceTest->value != originalTest->value ){
        printf("%%TEST_FAILED%% time=0 testname=testSeriesStruct (seriesSimpleTest) message=Expected element 3, value 32 and equal to element 4 in series.\n");
    }
    
    SeriesList* list = newSeriesList();
    
    if (list->length != 0 ){
        printf("%%TEST_FAILED%% time=0 testname=testSeriesStruct (seriesSimpleTest) message=Expected 0 series in list.\n");
    }
    
    appendToSeriesList(series, list);
    
    if (list->length != 1 ){
        printf("%%TEST_FAILED%% time=0 testname=testSeriesStruct (seriesSimpleTest) message=Expected 1 series in list.\n");
    }
    
    appendToSeriesList(slice, list);
    
    if (list->length != 2 ){
        printf("%%TEST_FAILED%% time=0 testname=testSeriesStruct (seriesSimpleTest) message=Expected 2 series in list.\n");
    }
    
}

int main(int argc, char** argv) {
    printf("%%SUITE_STARTING%% seriesSimpleTest\n");
    printf("%%SUITE_STARTED%%\n");

    printf("%%TEST_STARTED%% testSeriesStruct (seriesSimpleTest)\n");
    testSeriesStruct();
    printf("%%TEST_FINISHED%% time=0 testSeriesStruct (seriesSimpleTest) \n");
    
    
    printf("%%SUITE_FINISHED%% time=0\n");

    return (EXIT_SUCCESS);
}
