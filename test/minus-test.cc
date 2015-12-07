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
#include "storm/exception.h"
#include "storm/topology-context.h"
#include "storm/tuple.h"
#include "storm/storm.h"


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
using storm::ToValue;
using storm::g_allocator;
using storm::Tuple;

using namespace storm;

namespace testbolt {

class Minus: public Bolt {
public:
    virtual void Execute(Tuple *tuple) {
        Values result;
        result.SetArray();
        stringstream ss;
        ss << tuple->values()[0].GetInt() - tuple->values()[1].GetInt();
        result.PushBack(ToValue(ss.str()), g_allocator);
//        result.PushBack(tuple->mutable_values()[2], g_allocator);
        oc().Emit("default", tuple, &result);
        oc().Ack(tuple);
    }

private:
};

}  // anonymous namespace

TEST(BoltTest, Execute) {
    Values values;
    values.SetArray();
    values.PushBack(2, g_allocator);
    values.PushBack(1, g_allocator);
    Tuple tuple(move(values));

    stringstream ss;
    Values result;

    int i = tuple.values()[0].GetInt() - tuple.values()[1].GetInt();
    ss << i;
    result.SetArray();
    result.PushBack(ToValue(ss.str()), g_allocator);
    ASSERT_EQ(1,result.Size());

//    stringstream boltin;
//    stringstream boltout;
//    boltin<<"hello";
//    boltout<<"world";
//    unique_ptr<testbolt::Minus> minus { new testbolt::Minus() };
//    minus->Run(boltin, boltout);
}
