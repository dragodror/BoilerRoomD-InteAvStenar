//Load input image
var inputImg = require("luminance")(require("inputImg-image"))

//Allocate storage for result
var result = require("zeros")([512, 512])

//Rotate the image
require("image-rotate")(result, baboon, Math.PI / 6.0)

//Save the result
require("save-pixels")(result, "png").pipe(process.stdout)
