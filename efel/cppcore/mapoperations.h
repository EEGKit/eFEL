/* Copyright (c) 2015, EPFL/Blue Brain Project                                   
 *                                                                               
 * This file is part of eFEL <https://github.com/BlueBrain/eFEL>                 
 *                                                                               
 * This library is free software; you can redistribute it and/or modify it under 
 * the terms of the GNU Lesser General Public License version 3.0 as published   
 * by the Free Software Foundation.                                              
 *                                                                               
 * This library is distributed in the hope that it will be useful, but WITHOUT   
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS 
 * FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for more 
 * details.                                                                      
 *                                                                               
 * You should have received a copy of the GNU Lesser General Public License      
 * along with this library; if not, write to the Free Software Foundation, Inc., 
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.                   
 */      


#ifndef MAPOPERATIONS_H
#define MAPOPERATIONS_H

#include "types.h"

#include <map>
#include <string>
#include <vector>


extern std::string GErrorStr;

int getIntParam(mapStr2intVec& IntFeatureData, const std::string& param,
                std::vector<int>& vec);
int getDoubleParam(mapStr2doubleVec& DoubleFeatureData, const std::string& param,
                   std::vector<double>& vec);
int getStrParam(mapStr2Str& StringData, const std::string& param, std::string& value);
template <class T>
void setVec(std::map<std::string, std::vector<T> >& FeatureData, mapStr2Str& StringData,
               std::string key, const std::vector<T>& value);
template <class T>
int getVec(std::map<std::string, std::vector<T> >& FeatureData, mapStr2Str& StringData,
                 std::string strFeature, std::vector<T>& v);
template <class T>
int CheckInMap(std::map<std::string, std::vector<T> >& FeatureData,
                     mapStr2Str& StringData, std::string strFeature, int& nSize);
// eCode feature convenience function
int mean_traces_double(mapStr2doubleVec& DoubleFeatureData,
                       const std::string& feature, const std::string& stimulus_name,
                       int i_elem, std::vector<double>& mean);
int std_traces_double(mapStr2doubleVec& DoubleFeatureData,
                      const std::string& feature, const std::string& stimulus_name,
                      double mean, int i_elem, std::vector<double>& std);
void getTraces(mapStr2doubleVec& DoubleFeatureData, const std::string& wildcard,
               std::vector<std::string>& traces);

#endif
