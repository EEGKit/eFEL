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

#ifndef __DEPENDENCYTREE_H
#define __DEPENDENCYTREE_H

#include "types.h"

#include <list>
#include <map>
#include <string>
#include <utility>
#include <vector>

class cTree {
  std::vector<std::string> strDependencyFile;
  std::vector<std::string> vecFeature;

 public:
  std::string ErrorStr;
  std::list<std::string> FinalList;
  std::list<std::string> ChildList;
  cTree() {};
  cTree(const char *strFileName);
  int getDependencyList(std::string str);
  int setFeaturePointers(std::map<std::string, feature2function *> &mapFptrLib,
                         feature2function *FptrTable,
                         std::map<std::string, std::vector<feature_function> > *FptrLookup);

  int setFeaturePointers(std::map<std::string, feature2function *> &mapFptrLib,
                         feature2function *FptrTable,
                         std::map<std::string, std::vector<featureStringPair > > *FptrLookup);
  int getChilds(std::string strLine, std::list<std::string> &childs);
  int getDependency(std::string strLine, std::string parent_stim);
  int AddUniqueItem(std::string strFeature, std::list<std::string> &lstFinal);
  int getAllParents(std::vector<std::string> &vecFeature);
};

#endif
