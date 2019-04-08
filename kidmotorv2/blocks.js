Blockly.Blocks["kidmotor_motor"] = {
	init: function() {
		this.jsonInit({
			"message0": Blockly.Msg.KIDMOTOR_MOTOR_MESSAGE,
			"args0": [{
				"type": "field_dropdown",
				"name": "n",
				"options": [
					[ "1", "1" ],
					[ "2", "2" ]
				]
			}, {
				"type": "field_dropdown",
				"name": "dir",
				"options": [
					[ Blockly.Msg.KIDMOTOR_MOTOR_FORWARD_MESSAGE, "1" ],
					[ Blockly.Msg.KIDMOTOR_MOTOR_BACKWARD_MESSAGE, "0" ]
				]
			}, {
				"type": "input_value",
				"name": "value",
				"check": "Number"
			}],
			"inputsInline": true,
			"previousStatement": null,
			"nextStatement": null,
			"colour": 45,
			"tooltip": Blockly.Msg.KIDMOTOR_MOTOR_TOOLTIP,
			"helpUrl": "https://www.ioxhop.com/"
		});
	}
};

