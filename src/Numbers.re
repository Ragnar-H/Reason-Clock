open BsReactNative;

type option = {
  value: string,
  key: string,
};

module Styles = {
  open Style;

  let container =
    style([
      margin(Pt(24.)),
      padding(Pt(8.)),
      flexDirection(Column),
      backgroundColor(String("#91006F")),
    ]);

  let text = style([color(String("#ffa500")), fontSize(Float(24.))]);

  let selectedValue = style([backgroundColor(String("#fefefe"))]);
};

let textStyle = is_current =>
  is_current ? Style.combine(Styles.selectedValue, Styles.text) : Styles.text;

let component = ReasonReact.statelessComponent("Numbers");

let make = (~options, ~selectedValue, _children) => {
  ...component, /* spread the template's other defaults into here  */
  render: _self =>
    <View style=Styles.container>
      {
        ReasonReact.array(
          Array.of_list(
            List.map(
              option =>
                <Text
                  key={option.key}
                  style={textStyle(selectedValue == option.value)}>
                  {ReasonReact.string(option.value)}
                </Text>,
              options,
            ),
          ),
        )
      }
    </View>,
};