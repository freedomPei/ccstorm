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

TEST(ComponentTest, Run_Legal) {
//    stringstream ss;//    ss << "{\"count\":12}\nend\n"
//       << "{\"object\":{\"message\":\"hello, world\"}}\nend\n";
//
//    json::Value message = NextMessage(ss);
//    ASSERT_EQ(12, message["count"].GetInt());
//
//    message = NextMessage(ss);
//    ASSERT_STREQ("hello, world", message["object"]["message"].GetString());
     stringstream ssin;
//     stringstream ssout;
//     ssin << "{\"count\":12}\nend\n";
//     ssout << "{\"count\":15}\nend\n";
     Component comp;
     stringstream ss;
     json::Value msg = NextMessage(ss);
     comp.Log("hello,world");

}