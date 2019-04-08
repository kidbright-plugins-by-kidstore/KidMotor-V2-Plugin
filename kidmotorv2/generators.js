Blockly.JavaScript['kidmotor_motor'] = function(block) {
  var dropdown_n = block.getFieldValue('n');
  var dropdown_dir = block.getFieldValue('dir');
  var value_value = Blockly.JavaScript.valueToCode(block, 'value', Blockly.JavaScript.ORDER_ATOMIC);

  var code = 'DEV_I2C1.KidMotorV2(0, 0x65).setMotor(' + dropdown_n + ', ' + dropdown_dir + ', ' + value_value + ');\n';
  return code;
};
