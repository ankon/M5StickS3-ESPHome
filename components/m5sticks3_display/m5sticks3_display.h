#pragma once

#include "esphome/core/component.h"
#include "esphome/components/display/display_buffer.h"
#include <M5Unified.h>

namespace esphome {
namespace m5sticks3_display {

class M5StickS3Display : public display::DisplayBuffer {
 public:
  void setup() override;
  void update() override;
  void draw_absolute_pixel_internal(int x, int y, Color color) override;
  int get_width_internal() override;
  int get_height_internal() override;
  float get_setup_priority() const override { return setup_priority::PROCESSOR; }
  void dump_config() override;

  display::DisplayType get_display_type() override {
    return display::DisplayType::DISPLAY_TYPE_COLOR;
  }

  float get_setup_priority() const override {
    // 901: before i2c(900), after on_boot(1000)
    return esphome::setup_priority::BUS + 1;
  } 

 protected:
  bool initialized_{false};
  M5Canvas canvas_{&M5.Display};
};

}  // namespace m5sticks3_display
}  // namespace esphome
