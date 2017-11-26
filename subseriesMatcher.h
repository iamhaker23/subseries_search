/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   subseriesMatcher.h
 * Author: Hakeem
 *
 * Created on 22 November 2017, 18:51
 */

#ifndef SUBSERIESMATCHER_H
#define SUBSERIESMATCHER_H

#include "series.h"


#ifdef __cplusplus
extern "C" {
#endif

    typedef struct _Result{
        int seriesIndex;
        int startOfSequenceIndex;
        int lengthOfMatch;
        double distance;
    } Result;

    Result* subseriesMatching(Series* lookingFor, SeriesList* inSeriesList);
    
    Result* subseriesMatching_log_mem(Series* lookingFor, SeriesList* inSeriesList, FILE* log);
    Result* subseriesMatching_log_mem_optimisation_6(Series* lookingFor, SeriesList* inSeriesList, FILE* log);
    
    Result* subseriesMatching_w_optimisation_1(Series* lookingFor, SeriesList* inSeriesList);
    Result* subseriesMatching_w_optimisation_2(Series* lookingFor, SeriesList* inSeriesList);
    Result* subseriesMatching_w_optimisation_3(Series* lookingFor, SeriesList* inSeriesList);
    Result* subseriesMatching_w_optimisation_4(Series* lookingFor, SeriesList* inSeriesList);
    
    double distance(Series* a, Series* b);
    double distance_w_optimisation_1(Series* a, Series* b);

#ifdef __cplusplus
}
#endif

#endif /* SUBSERIESMATCHER_H */

