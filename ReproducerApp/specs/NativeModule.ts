import { TurboModule, TurboModuleRegistry } from 'react-native';

export interface Spec extends TurboModule {

    observeNativeUpdater(observer: (value: string) => void) : Object
}

export default TurboModuleRegistry.getEnforcing<Spec>(
    'NativeModule',
  );