// Copyright (c) 2015 ShuMei Inc. All rights reserved.
// Authors: Liang Kun <liangkun@ishumei.com>.

#include <cstdlib>
#include <memory>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <utility>
#include "gtest/gtest.h"
#include "storm/json.h"
#include "storm/exception.h"
#include "storm/tuple.h"
#include "storm/internal/protocol.h"

using std::remove;
using std::ostream;
using std::stringstream;
using std::string;
using std::unique_ptr;
using std::vector;
using std::move;
using std::ios_base;
using storm::TopologyContext;
using storm::ProtocolException;
using storm::Value;
using storm::Values;
using storm::g_allocator;
using storm::Tuple;
using namespace storm::internal::protocol;
namespace json = storm::json;


TEST(BoltTest, testExecute) {
//      const string json { "{\n"
//                                  "    \"a\": [2, 1]\n"
//                          "}" };

//      json::Document document(&g_allocator);
//      document.Parse(json.c_str());

    Values values;
    values.SetArray();
    values.PushBack("2", g_allocator);
    values.PushBack("1", g_allocator);


//      Values &a = document["a"];
      Tuple tuple(values);
      int i=0;
      stringstream ss;
      Values result;

      i = (tuple.values()[0].GetInt() - tuple.values()[1].GetInt());
      ss<<i;
      ASSERT_EQ(1,i);
      result.PushBack(ToValue(ss.str()), g_allocator);
      result.PushBack(tuple->mutable_values()[2], g_allocator);
      ASSERT_EQ(2,result.size());
}
