//
// Created by fss on 22-11-22.
//
#include <benchmark/benchmark.h>
#include "runtime/runtime_ir.hpp"
const int kIterationNum = 5;

static void BM_Resnet18(benchmark::State &state) {
  using namespace kuiper_infer;
  RuntimeGraph graph("tmp/resnet/resnet18_batch8.pnnx.param",
                     "tmp/resnet/resnet18_batch8.pnnx.bin");

  graph.Build("pnnx_input_0", "pnnx_output_0");
  std::shared_ptr<Tensor<float>> input1 = std::make_shared<Tensor<float>>(3, 224, 224);
  input1->Fill(1.);

  std::shared_ptr<Tensor<float>> input2 = std::make_shared<Tensor<float>>(3, 224, 224);
  input2->Fill(1.);

  std::shared_ptr<Tensor<float>> input3 = std::make_shared<Tensor<float>>(3, 224, 224);
  input3->Fill(1.);

  std::shared_ptr<Tensor<float>> input4 = std::make_shared<Tensor<float>>(3, 224, 224);
  input4->Fill(1.);

  std::shared_ptr<Tensor<float>> input5 = std::make_shared<Tensor<float>>(3, 224, 224);
  input5->Fill(1.);

  std::shared_ptr<Tensor<float>> input6 = std::make_shared<Tensor<float>>(3, 224, 224);
  input6->Fill(1.);

  std::shared_ptr<Tensor<float>> input7 = std::make_shared<Tensor<float>>(3, 224, 224);
  input7->Fill(1.);

  std::shared_ptr<Tensor<float>> input8 = std::make_shared<Tensor<float>>(3, 224, 224);
  input8->Fill(1.);

  std::vector<std::shared_ptr<Tensor<float>>> inputs;
  inputs.push_back(input1);
  inputs.push_back(input2);
  inputs.push_back(input3);
  inputs.push_back(input4);
  inputs.push_back(input5);
  inputs.push_back(input6);
  inputs.push_back(input7);
  inputs.push_back(input8);

  for (auto _ : state) {
    std::vector<std::shared_ptr<Tensor<float>>> output_tensors = graph.Forward(inputs, false);
  }
}

static void BM_Resnet18_Batch16(benchmark::State &state) {
  using namespace kuiper_infer;
  RuntimeGraph graph("tmp/resnet/resnet18_batch16.pnnx.param",
                     "tmp/resnet/resnet18_batch16.pnnx.bin");

  graph.Build("pnnx_input_0", "pnnx_output_0");

  std::vector<std::shared_ptr<Tensor<float>>> inputs;
  for (int i = 0; i < 16; ++i) {
    std::shared_ptr<Tensor<float>> input1 = std::make_shared<Tensor<float>>(3, 224, 224);
    input1->Fill(1.);
    inputs.push_back(input1);
  }

  for (auto _ : state) {
    std::vector<std::shared_ptr<Tensor<float>>> output_tensors = graph.Forward(inputs, false);
  }
}

static void BM_MobilenetV3(benchmark::State &state) {
  using namespace kuiper_infer;
  RuntimeGraph graph("tmp/mobilenet/mobile_batch8.pnnx.param",
                     "tmp/mobilenet/mobile_batch8.bin");

  graph.Build("pnnx_input_0", "pnnx_output_0");
  std::shared_ptr<Tensor<float>> input1 = std::make_shared<Tensor<float>>(3, 224, 224);
  input1->Fill(1.);

  std::shared_ptr<Tensor<float>> input2 = std::make_shared<Tensor<float>>(3, 224, 224);
  input2->Fill(1.);

  std::shared_ptr<Tensor<float>> input3 = std::make_shared<Tensor<float>>(3, 224, 224);
  input3->Fill(1.);

  std::shared_ptr<Tensor<float>> input4 = std::make_shared<Tensor<float>>(3, 224, 224);
  input4->Fill(1.);

  std::shared_ptr<Tensor<float>> input5 = std::make_shared<Tensor<float>>(3, 224, 224);
  input5->Fill(1.);

  std::shared_ptr<Tensor<float>> input6 = std::make_shared<Tensor<float>>(3, 224, 224);
  input6->Fill(1.);

  std::shared_ptr<Tensor<float>> input7 = std::make_shared<Tensor<float>>(3, 224, 224);
  input7->Fill(1.);

  std::shared_ptr<Tensor<float>> input8 = std::make_shared<Tensor<float>>(3, 224, 224);
  input8->Fill(1.);

  std::vector<std::shared_ptr<Tensor<float>>> inputs;
  inputs.push_back(input1);
  inputs.push_back(input2);
  inputs.push_back(input3);
  inputs.push_back(input4);
  inputs.push_back(input5);
  inputs.push_back(input6);
  inputs.push_back(input7);
  inputs.push_back(input8);

  for (auto _ : state) {
    std::vector<std::shared_ptr<Tensor<float>>> output_tensors = graph.Forward(inputs, false);
  }
}

BENCHMARK(BM_Resnet18)->Iterations(kIterationNum);
BENCHMARK(BM_Resnet18_Batch16)->Iterations(kIterationNum);
BENCHMARK(BM_MobilenetV3)->Iterations(kIterationNum);

BENCHMARK_MAIN();