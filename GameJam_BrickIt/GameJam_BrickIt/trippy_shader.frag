uniform sampler2D texture;
uniform float time;

void main() {
    vec2 uv = gl_TexCoord[0].xy;

    uv.x += sin(uv.y * 5 + time) /20;

    vec4 color = texture2D(texture, uv);

    color.r = abs(cos(color.r + time));
    color.g = abs(sin(color.g - time));
    color.b = abs(sin(color.b + time));

    gl_FragColor = color; 
}
