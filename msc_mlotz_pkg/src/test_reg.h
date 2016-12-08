/*
 * Copyright (c) 2014-2015, Robot Control and Pattern Recognition Group, Warsaw University of Technology.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of the Robot Control and Pattern Recognition Group,
 *       Warsaw University of Technology nor the names of its contributors may
 *       be used to endorse or promote products derived from this software
 *       without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef TESTREG_H_
#define TESTREG_H_

#include <std_msgs/Bool.h>

#include <string>

class test_reg : public RTT::TaskContext {
 public:
  explicit test_reg(const std::string& name);
  ~test_reg();

  int doServo(double, double);
  void reset();

 private:
  bool configureHook();
  void updateHook();
  bool startHook();

  RTT::InputPort<double> desired_position_;
  RTT::InputPort<double> measured_position_;
  // RTT::InputPort<bool> synchro_state_in_;
  RTT::InputPort<bool> reset_signal_in_;

  RTT::OutputPort<double> computed_current_out_;
  RTT::OutputPort<std_msgs::Bool> emergency_stop_out_;

  double desired_position_increment_;
  double desired_position_old_, desired_position_new_;
  double measured_position_old_, measured_position_new_;
  double deltaIncData;

  bool synchro_state_old_, synchro_state_new_;

  int64_t update_hook_iteration_number_;
  int64_t new_position_iteration_number_;

  // Properties
  bool debug_;
  double A_;
  double BB0_;
  double BB1_;
  double max_output_current_;
  double current_reg_kp_;
  double eint_dif_;
  double max_desired_increment_;
  double max_position_error_;
  double enc_res_;
  double output_multiplicator_;

  // przedosatnio odczytany przyrost polozenie (delta y[k-2]
  double position_increment_old;
  // -- mierzone w impulsach)
  // ostatnio odczytany przyrost polozenie (delta y[k-1]
  double position_increment_new;
  // -- mierzone w impulsach)
  // poprzednia wartosc zadana dla jednego kroku regulacji
  double step_old_pulse;
  // (przyrost wartosci zadanej polozenia -- delta r[k-2]
  // -- mierzone w radianach)
  double step_new;  // nastepna wartosc zadana dla jednego kroku regulacji
  // (przyrost wartosci zadanej polozenia -- delta r[k-1]
  // -- mierzone w radianach)
  double step_old;  // poprzednia wartosc zadana dla jednego kroku regulacji
  // (przyrost wartosci zadanej polozenia -- delta r[k-1]
  // -- mierzone w radianach)

  // wielkosc kroku do realizacji przez HI (wypelnienie PWM -- u[k])
  double set_value_new;
  // wielkosc kroku do realizacji przez HI (wypelnienie PWM -- u[k-1])
  double set_value_old;
  // wielkosc kroku do realizacji przez HI (wypelnienie PWM -- u[k-2])
  double set_value_very_old;
  double delta_eint;  // przyrost calki uchybu
  double delta_eint_old;  // przyrost calki uchybu w poprzednim kroku

  double output_value;

  double a_, b0_, b1_;
};
#endif // IRP6REGULATOR_H_
