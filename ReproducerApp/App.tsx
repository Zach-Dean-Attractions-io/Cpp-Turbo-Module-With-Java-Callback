/**
 * Sample React Native App
 * https://github.com/facebook/react-native
 *
 * @format
 */

import React, { useEffect } from 'react';
import {
  SafeAreaView,
  Text,
} from 'react-native';
import NativeModule from './specs/NativeModule';

function App(): React.JSX.Element {

  useEffect(() => {
     NativeModule.observeNativeUpdater((value: string) => {
      console.log("Observer");
    })
  }, []);

  return (
    <SafeAreaView>
      <Text>Hello World</Text>
    </SafeAreaView>
  );
}

export default App;
