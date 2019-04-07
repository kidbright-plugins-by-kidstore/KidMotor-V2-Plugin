Blockly.Blocks["kidmotor_motor"] = {
	init: function() {
		this.jsonInit({
			"message0": "motor  %1 move %2 at speed %3",
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
					[ "forward", "1" ],
					[ "backward", "0" ]
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
			"tooltip": "Change direction and speed of motor in channel 1 or 2",
			"helpUrl": "https://www.ioxhop.com/"
		});
	}
};

