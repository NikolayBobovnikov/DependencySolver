#pragma once

#include "target.h"
#include <iostream>
#include <format>
#include <exception>

TargetManager::TargetManager(){};

  std::unique_ptr<Target> TargetManager::CreateTarget(size_t id, std::function<void()> task) {
    if (tasks.count(id) != 0) {
      throw std::invalid_argument(std::format("Target id {} already exists.", id));
    }

    std::unique_ptr<Target> target;

    try {
      target = std::make_unique<Target>(id, task);
      tasks.insert(id);
    } catch (...) {
      throw;
    }
   
    return target;
  }

  std::unique_ptr<Target> TargetManager::CreateTarget(size_t id) {
    return CreateTarget(id, [=]() { std::cout << "Target " << id << std::endl; });
  }