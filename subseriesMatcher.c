/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "series.h"
#include "subseriesMatcher.h"
#include <math.h>
#include <errno.h>
#include <float.h>


Result* subseriesMatching(Series* lookingFor, SeriesList* inSeriesList){
    Result* result = (Result*)malloc(sizeof(Result));
    
    float lowestDistance = FLT_MAX;
    int seriesIndex = -1;
    int subseriesStart = -1;
    int k = lookingFor->length;
    //Assumes a square series list (e.g. n series, each of n length)
    //So n is used interchangeably for limits of inSeriesList and inSeriesList elements
    int n = inSeriesList->length;
    
    if (n >= k){
        for (int i = 0; i < n; i++){
        
            Series* originalSeries = getSNode(i, inSeriesList)->series;
            for (int j = 0; j < (n+1)-k; j++){
                
                //-1 from k because of zero-indexing
                Series* currentSubseries = sliceSeries(originalSeries, j, j+(k-1));
                
                double currentDistance = distance(lookingFor, currentSubseries);
                
                if (currentDistance < lowestDistance){
                    lowestDistance = currentDistance;
                    seriesIndex = i;
                    subseriesStart = j;
                }else if (currentDistance == lowestDistance){
                    //handle tie
                    lowestDistance = currentDistance;
                    seriesIndex = i;
                    subseriesStart = j;
                }
                
            }
        }
    }else{
        fprintf(stderr, "Cannot find match for subseries length %d in series length %d.\n", k, n);
        exit(EXIT_FAILURE);
    }
    
    result->distance = lowestDistance;
    result->lengthOfMatch = lookingFor->length;
    result->seriesIndex = seriesIndex;
    result->startOfSequenceIndex = subseriesStart;
    
    return result;
}


double distance(Series* a, Series* b){
    
    double totalSquareDifferences = 0.0f;
    
    if ((a->length - b->length) == 0){
        for (int i = 0; i < a->length; i++){
            int diff = (getElement(i, a)->value - getElement(i, b)->value);
            totalSquareDifferences = totalSquareDifferences + (diff*diff);
        }
    }else{
        fprintf(stderr, "Could not calculate distance for two series of differing lengths.\n");
        exit(EXIT_FAILURE);
    }
    
    return sqrt(totalSquareDifferences);
}