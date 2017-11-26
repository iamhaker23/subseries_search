/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

//to retrieve (and verify) the closest matching slice
//sliceSeries(getSNode(result->seriesIndex, inSeriesList)->series, result->startOfSequenceIndex, result->startOfSequenceIndex + (result->lengthOfMatch-1))

#include "series.h"
#include "subseriesMatcher.h"
#include <math.h>
#include <errno.h>
#include <float.h>
#include <time.h>


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
                free(currentSubseries);
                
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
            totalSquareDifferences = totalSquareDifferences + (double)(diff*diff);
        }
    }else{
        fprintf(stderr, "Could not calculate distance for two series of differing lengths.\n");
        exit(EXIT_FAILURE);
    }
    
    return sqrt(totalSquareDifferences);
}

double distance_w_optimisation_1(Series* a, Series* b){
    
    double totalDistance = 0.0f;
    
    if ((a->length - b->length) == 0){
        for (int i = 0; i < a->length; i++){
            int diff = (getElement(i, a)->value - getElement(i, b)->value);
            totalDistance = totalDistance + (double)((diff < 0)?diff*-1:diff);
        }
    }else{
        fprintf(stderr, "Could not calculate distance for two series of differing lengths.\n");
        exit(EXIT_FAILURE);
    }
    
    return totalDistance;
}

Result* subseriesMatching_w_optimisation_1(Series* lookingFor, SeriesList* inSeriesList){

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
                
                double currentDistance = distance_w_optimisation_1(lookingFor, currentSubseries);
                
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
                free(currentSubseries);
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

Result* subseriesMatching_w_optimisation_2(Series* lookingFor, SeriesList* inSeriesList){

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
                    
                    if (currentDistance == 0){
                        result->distance = currentDistance;
                        result->lengthOfMatch = lookingFor->length;
                        result->seriesIndex = i;
                        result->startOfSequenceIndex = j;
                        return result;
                    }
                    
                    lowestDistance = currentDistance;
                    seriesIndex = i;
                    subseriesStart = j;
                }else if (currentDistance == lowestDistance){
                    //handle tie
                    lowestDistance = currentDistance;
                    seriesIndex = i;
                    subseriesStart = j;
                }
                free(currentSubseries);
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


Result* subseriesMatching_w_optimisation_3(Series* lookingFor, SeriesList* inSeriesList){
    
    Result* result = (Result*)malloc(sizeof(Result));
    SeriesList* cache = newSeriesList();
    int cacheHits = 0;
    
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
                
                double currentDistance = FLT_MAX;
                
                if (seriesListContains(cache, currentSubseries) == -1){
                    currentDistance = distance(lookingFor, currentSubseries);
                    appendToSeriesList(currentSubseries, cache);
                }else{
                    cacheHits = cacheHits + 1;
                }
                
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
    
    printf("Cache Hits: %d\n", cacheHits);
    
    return result;
}


Result* subseriesMatching_w_optimisation_4(Series* lookingFor, SeriesList* inSeriesList, SeriesList* bakedCache){
    
    Result* result = (Result*)malloc(sizeof(Result));
    
    int givenCache = (bakedCache != NULL)?1:0;
    SeriesList* cache = (givenCache==1) ? bakedCache : newSeriesList();
    
    
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
                
                double currentDistance = FLT_MAX;                
                
                SeriesList* deltas = NULL;
                
                if ((givenCache == 1)){// && ((deltas = getShortestDeltaSeries(cache, currentSubseries, lookingFor)) &&  (deltas != NULL && deltas->first->distance < lowestDistance && deltas->first->series->length < lookingFor->length))){
                    
                    deltas = getShortestDeltaSeries(cache, currentSubseries, lookingFor);
                    currentDistance = deltas->first->distance + distance(deltas->first->series, deltas->last->series);
                    //printf("%lf -> %lf\n", deltas->first->distance, currentDistance);
                }else{
                    //original code
                    currentDistance = distance(lookingFor, currentSubseries);
                }
                
                if (currentDistance < lowestDistance){
                    lowestDistance = currentDistance;
                    seriesIndex = i;
                    subseriesStart = j;
                    
                    if (givenCache == 0){
                        //only cache the lowest
                        freeSeriesList(cache);
                        cache = newSeriesList();
                        cacheSeries(currentSubseries, currentDistance, cache);
                    }else{
                        free(currentSubseries);
                    }
                    
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
    result->cache = cache;
    
    return result;
}

Result* subseriesMatching_log_mem_optimisation_6(Series* lookingFor, SeriesList* inSeriesList, FILE* log){

    Result* result = (Result*)malloc(sizeof(Result));
    
    int memoryUsage = (inSeriesList->length * sizeof(SNode)) + (inSeriesList->length * inSeriesList->first->series->length * sizeof(Element));
  
    printf("Memory: %d\n", memoryUsage);
    fprintf(log, "%d,6\n", memoryUsage);
    
    
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
                free(currentSubseries);
            }
            
        }
    }else{
        fprintf(stderr, "Cannot find match for subseries length %d in series length %d.\n", k, n);
        exit(EXIT_FAILURE);
    }
    
    SNode* current = inSeriesList->first;
    while(current!=NULL){
        SNode* next = current->next;
        if (current->index != seriesIndex){
            removeSNode(current->index, inSeriesList);
        }
        current=next;
    }
    
    result->distance = lowestDistance;
    result->lengthOfMatch = lookingFor->length;
    result->seriesIndex = seriesIndex;
    result->startOfSequenceIndex = subseriesStart;

    memoryUsage = (inSeriesList->length * sizeof(SNode)) + (inSeriesList->length * inSeriesList->first->series->length * sizeof(Element));
            
    printf("Memory: %d\n", memoryUsage);
    fprintf(log, "%d,6\n", memoryUsage);
    
    
    return result;
}

Result* subseriesMatching_log_mem(Series* lookingFor, SeriesList* inSeriesList, FILE* log){
    Result* result = (Result*)malloc(sizeof(Result));
    
    int memoryUsage = (inSeriesList->length * sizeof(SNode)) + (inSeriesList->length * inSeriesList->first->series->length * sizeof(Element));
  
    printf("Memory: %d\n", memoryUsage);
    fprintf(log, "%d,0\n", memoryUsage);
    
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
                free(currentSubseries);
                
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

    memoryUsage = (inSeriesList->length * sizeof(SNode)) + (inSeriesList->length * inSeriesList->first->series->length * sizeof(Element));
            
    printf("Memory: %d\n", memoryUsage);
    fprintf(log, "%d,0\n", memoryUsage);
    
    return result;
}
