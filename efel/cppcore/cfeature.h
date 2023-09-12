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
      
#ifndef CFEATURE_H_
#define CFEATURE_H_

#include "types.h"

#include <map>
#include <string>
#include <vector>
#include <math.h>

#include "FillFptrTable.h"
#include "DependencyTree.h"
#include "eFELLogger.h"


class cFeature {
  mapStr2intVec mapIntData;
  mapStr2doubleVec mapDoubleData;
  mapStr2Str mapStrData;
  std::map<std::string, std::string> featuretypes;
  FILE* fin;
  void fillfeaturetypes();

 public:
  std::map<std::string, std::vector<featureStringPair > > fptrlookup;
  std::vector<int>& getmapIntData(std::string strName);
  std::vector<double>& getmapDoubleData(std::string strName);

  eFELLogger logger;

  cFeature(const std::string& depFile, const std::string& outdir);
  int getmapfptrVec(std::string strName, std::vector<feature_function>& vFptr);
  int calc_features(const std::string& name);
  int setFeatureInt(std::string strName, std::vector<int>& intVec);
  int getFeatureInt(std::string strName, std::vector<int>& vec);
  int setFeatureDouble(std::string strName, std::vector<double>& DoubleVec);
  int getFeatureDouble(std::string strName, std::vector<double>& vec);
  int setFeatureString(const std::string& key, const std::string& value);
  int getFeatureString(const std::string& key, std::string& value);
  void getTraces(const std::string& wildcard, std::vector<std::string>& traces);
  int printFeature(const char* strFileName);
  int printMapMember(FILE* fp);

  std::string featuretype(std::string featurename);
  std::string getGError();
  void get_feature_names(std::vector<std::string>& feature_names);
  int setVersion(std::string strDepFile);
  double getDistance(std::string strName, double mean, double std, 
          bool trace_check=true, double error_dist=250);

  // calculation of GA errors
  template<typename T>
  double calc_error_bio(const std::vector<T>& v, double bio_mean, double bio_sd)
  {
    if (v.size() != 0) {
      double error = 0.;
      for (size_t i = 0; i < v.size(); i++) {
        error += fabs(v[i] - bio_mean);
      }
      return error / bio_sd / v.size();
    } else {
      return 250.;
    }
  }
};

#endif
