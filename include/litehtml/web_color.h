#ifndef LH_WEB_COLOR_H
#define LH_WEB_COLOR_H

namespace litehtml
{
	class document_container;

	struct web_color
	{
		byte red   = 0;
		byte green = 0;
		byte blue  = 0;
		byte alpha = 255;
		bool is_current_color = false;

		static const web_color transparent;
		static const web_color black;
		static const web_color white;
		static const web_color current_color;

		web_color() {}
		web_color(byte r, byte g, byte b, byte a = 255) : red(r), green(g), blue(b), alpha(a) {}
		web_color(bool is_current_color) : is_current_color(is_current_color) {}

		bool operator==(web_color color) const { return red == color.red && green == color.green && blue == color.blue && alpha == color.alpha; }
		bool operator!=(web_color color) const { return !(*this == color); }

		bool from_token(const css_token& token, document_container* container);
		web_color darken(double fraction) const;
		string to_string() const;

	private:
		bool parse_hash_token(const css_token& token);
		bool parse_function_token(const css_token& token);
		bool parse_rgb_func(const css_token& token);
		bool parse_hsl_func(const css_token& token);
		bool parse_ident_token(const css_token& token, document_container* container);
	};
}

#endif  // LH_WEB_COLOR_H
