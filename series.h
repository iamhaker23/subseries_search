/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   series.h
 * Author: Hakeem
 *
 * Created on 22 November 2017, 17:43
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef SERIES_H
#define SERIES_H

#ifdef __cplusplus
extern "C" {
#endif

    #ifndef MAX_RANDOM_VALUE
        int MAX_RANDOM_VALUE;
    #endif
    
    typedef struct _Element{
        int value;
        int index;
        struct _Element* next;
        struct _Element* previous;
    } Element;
    
    typedef struct _Series{
        Element* first;
        Element* last;
        int length;
    } Series;
    
    typedef struct _seriesListNode{
        Series* series;
        struct _seriesListNode* next;
        struct _seriesListNode* previous;
        int index;
        float distance;
        char* asString;
    }SNode;
    
    
    char* seriesAsString(Series* series, int fieldLength);
    
    typedef struct _seriesList{
        SNode* first;
        SNode* last;
        int length;
    } SeriesList;
    
    
    
    Element* getElement(int index, Series* series);
    Series* newSeries();
    void appendToSeries(int value, Series* series);
    Series* sliceSeries(Series* series, int start, int end);
    SNode* getSNode(int index, SeriesList* seriesList);
    void removeSNode(int index, SeriesList* seriesList);
    
    SeriesList* newSeriesList();
    void appendToSeriesList(Series* series, SeriesList* seriesList);
    void cacheSeries(Series* series, float distance, SeriesList* seriesList);
    
    void randomlyPopulateSeries(int n, Series* series);
    void randomlyPopulateSeriesList(int n, SeriesList* list);
    
    void printSeries(Series* series);
    void printSeriesList(SeriesList* list);
    
    int seriesListContains(SeriesList* list, Series* series);
    
    void freeSeriesList(SeriesList* list);
    
    Series* duplicateSeries(Series* series);
    SeriesList* duplicateSeriesList(SeriesList* series);
    
    SeriesList* getShortestDeltaSeries(SeriesList* cache, Series* givenSubSeries, Series* lookingFor);
    

#ifdef __cplusplus
}
#endif

#endif /* SERIES_H */

